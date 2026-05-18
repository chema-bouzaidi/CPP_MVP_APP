# AirWatcher — Contexte projet pour Claude Code

> Ce fichier sert de mémoire long-terme pour Claude Code. Il résume l'architecture, les conventions et les choix de conception faits pour le projet **AirWatcher**. À lire en début de session pour comprendre le contexte.

---

## 1. Présentation du projet

**AirWatcher** est une application **console en C++** permettant à différents acteurs de surveiller et d'analyser la qualité de l'air à partir de données issues de capteurs.

### Acteurs (utilisateurs du système)
- **Admin** — Gère les comptes utilisateurs (création, suppression, bannissement)
- **Agency** (agence gouvernementale) — Surveille le réseau de capteurs, génère des stats, classe les capteurs
- **ExternalCompany** (entreprise externe) — Analyse l'efficacité de ses purificateurs (Cleaners)
- **PrivateIndividual** (particulier) — Possède un capteur privé, gagne des points de fiabilité

### Sources de données (CSV)
- `sensors.csv` — Capteurs publics et privés
- `measurements.csv` — Mesures relevées
- `attributes.csv` — Polluants mesurés (O3, NO2, SO2, PM10)
- `cleaners.csv` — Purificateurs d'air
- `providers.csv` — Fournisseurs (entreprises externes propriétaires des Cleaners)
- `users.csv` — Comptes utilisateurs

---

## 2. Architecture : MVC (et pas MVP)

L'archi est **Model-View-Controller**, avec une séparation stricte des responsabilités.

### Vue d'ensemble

```
┌──────────────────────┐         ┌──────────────────────┐
│ InterfaceUtilisateur │ ◄─────► │  Controleur (abstr.) │
│      (Vue/CLI)       │         │  ├─ ControleurAgence │
└──────────────────────┘         │  ├─ ControleurEntr.  │
                                 │  ├─ ControleurPart.  │
                                 │  └─ Authentifieur    │
                                 └──────────┬───────────┘
                                            │ utilise
                                            ▼
                                 ┌──────────────────────┐
                                 │       Model          │
                                 │  (données + métier)  │
                                 └──────────────────────┘
```

### Responsabilités

| Couche | Rôle | Ce qu'elle NE fait PAS |
|---|---|---|
| **Model** | Stocke les données, expose les requêtes (find, list, filter). Charge les CSV. | Ne connaît ni la vue ni les contrôleurs. Ne déclenche aucune action. |
| **Vue** (`InterfaceUtilisateur`) | Lit les entrées clavier, affiche les sorties console. Convertit `String` → objets métier (ex: `id` → `Sensor*`) avant de passer au contrôleur. | Ne contient aucune logique métier. |
| **Contrôleurs** | Orchestrent les use-cases. Un contrôleur abstrait + un par rôle (polymorphisme). | Ne stockent pas de données persistantes. |
| **Authentifieur** | Vérifie identifiant/mot de passe, retourne le `User` connecté ou null. | Ne gère pas les use-cases métier. |

---

## 3. Diagramme de classes — Liste des classes

### Acteurs (héritage de `User` abstrait)
- `User` — abstraite, contient `userID`, `password`, `role`, `isConnected`
- `Admin` — gère les comptes
- `Agency` — agence gouvernementale (juste un ID, données minimales)
- `ExternalCompany` — entreprise externe avec `companyID` + `providerID`
- `PrivateIndividual` — particulier avec `privateID`, `points`, `isReliable`

### Entités métier
- `Sensor` — capteur public (id, position, état)
  - `PrivateSensor` (sous-classe) — capteur privé, peut être marqué non-fiable
- `Measurement` — une mesure (valeur + timestamp + attribut + sensorId)
- `Attribute` — type de polluant (O3, NO2, etc.)
- `Cleaner` — purificateur d'air (position, période d'activité)
- `Provider` — propriétaire des Cleaners (composition `Provider ◆— Cleaner`)

### Logique applicative
- `AirQualityCalculator` — moteur de calcul (indice ATMO, qualité moyenne, niveau d'amélioration, rayon nettoyé)
- `Statistics` — encapsule les paramètres d'une requête stat (centre, rayon, période, mode) et le résultat

### Datatypes utilitaires (`<<datatype>>`)
- `Coordinates` — (latitude, longitude)
- `Period` — (startDate, endDate) avec méthodes `contains`, `duration`, `overlaps`

---

## 4. Conventions de conception

### a. Pas de `String id` en paramètre des contrôleurs

❌ **À éviter** :
```cpp
list<Sensor> findSimilarSensors(string sensorId, Period period);
```

✅ **À privilégier** :
```cpp
list<Sensor> findSimilarSensors(const Sensor& refSensor, const Period& period);
```

**Raison** : les contrôleurs manipulent des **objets métier**, pas des strings. La conversion `String → Sensor` est la responsabilité de la **Vue** (qui appelle `model.findSensor(id)` avant de transmettre au contrôleur).

### b. Datatypes vs Classes

- Une **classe** a une identité (deux Sensor avec le même ID restent deux objets distincts)
- Un **datatype** n'a pas d'identité, c'est juste une valeur (deux `Period(2025-01-01, 2025-12-31)` sont interchangeables)

→ `Coordinates` et `Period` sont des datatypes, donc passés **par valeur** ou par référence const, jamais alloués sur le tas.

### c. Visibilité

- `+` public (méthodes appelées par d'autres classes)
- `-` private (état interne)
- `#` protected (accessible par les sous-classes)

### d. Conventions de nommage

- Classes : `PascalCase` (ex: `AirQualityCalculator`)
- Méthodes / attributs : `camelCase` (ex: `findSimilarSensors`, `userID`)
- Pas de typos : `getAttributeId` (pas `getAtrributeId`), `authenticate` (pas `authentificate`)

### e. Composition vs Association

- **Composition** (losange noir plein) : ownership fort, le composant meurt avec le composé
  - `Model ◆— User` (les utilisateurs n'existent pas sans le système)
  - `Sensor ◆— Measurement` (les mesures appartiennent au capteur)
  - `Provider ◆— Cleaner`
- **Association** (ligne simple) : référence sans ownership
  - `Agency — Sensor` (l'agence consulte les capteurs mais ne les possède pas)

### f. Labels de relations

- Pour une composition, **pas** de verbe (ex: pas `manages`) — utiliser le **nom de rôle** (ex: `users`, `sensors`)
- Pour une association ou dépendance, un verbe métier court (ex: `monitors`, `analyzes`, `uses`)

---

## 5. Use-cases principaux (côté Agency)

D'après le sujet, l'agence peut :
1. **Analyser** la qualité de l'air sur une zone et une période → utilise `AirQualityCalculator`
2. **Classer les capteurs par similarité** → `findSimilarSensors(refSensor, period)`
3. **Signaler un capteur défectueux** → `markSensorDefective(sensor)`
4. **Exclure les données aberrantes** des capteurs privés malveillants → `flagPrivateSensorAsUnreliable(sensor)`

## 6. Use-cases côté ExternalCompany

1. **Analyser l'efficacité d'un Cleaner** sur sa période d'activité → `analyzeCleanerEfficiency(cleaner)`
2. **Comparer la qualité avant/pendant/après** un Cleaner → utilise `AirQualityCalculator.computeImprovement`

## 7. Use-cases côté PrivateIndividual

1. **Consulter ses points** de fiabilité
2. **Consulter** les mesures de son capteur privé

---

## 8. Lucidchart

Le diagramme de classes UML est sur Lucidchart, document ID : `e2179b59-ce85-4fad-8635-b6ba59c15db0`.

---

## 9. Équipe

Yessine TURKI — Ema GONCALVES — Hiba AMAMOU — Chema BOUZAIDI

---

## 10. Pièges connus / décisions à ne pas oublier

- ❗ Le `Authentifieur` doit dépendre du `Model` (`uses`) pour vérifier les credentials
- ❗ `ControleurEntreprise` doit dépendre de `Statistics` (il génère des stats sur les Cleaners)
- ❗ `monitors` / `generates` / `analyzes` sont des actions qui appartiennent aux **contrôleurs**, pas aux classes d'utilisateurs (Agency, ExternalCompany sont juste des données)
- ❗ Un `PrivateIndividual` possède **exactement un** `PrivateSensor` (multiplicité 1—1)
- ❗ `Coordinates` et `Period` sont des datatypes : pas de flèches de dépendance partout, on assume qu'ils sont utilisés comme types primitifs
