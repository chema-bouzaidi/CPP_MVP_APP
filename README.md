# AirWatcher

A **C++11** console application for air quality monitoring, built as a team project for the UML / software engineering course at INSA Lyon (4th year, 2026).

It loads pollution sensor readings (O3, NO2, SO2, PM10), computes the **ATMO air quality index** for a given area and period, and gives each type of user (administrator, government agency, company, private individual) the features relevant to them.

## Features

| Role | What they can do |
|---|---|
| **Administrator** | List, create, delete and ban users |
| **Government agency** | Compute the average air quality (ATMO index) over an area (center + radius) and a period; rank the sensors most **similar** to a reference sensor; flag a sensor as faulty; validate the reliability of private sensors; list all sensors |
| **Company (air purifier provider)** | View their purifiers; measure their **impact** on the ATMO index; compute the effective **cleaning radius** and improvement level (access restricted to their own purifiers) |
| **Private individual** | View their reliability points and the measurements of their own sensor over a period |

Technical highlights:
- ATMO index (1 to 10) computed from the O3, NO2, SO2 and PM10 sub-indices;
- sensor similarity ranking, with computation time displayed;
- statistical outlier filtering;
- role-based access control.

## Architecture

The project follows the **MVC** pattern and was designed from UML diagrams.

```
.
├── main.cpp            # entry point
├── Model/              # model: users, sensors, cleaners, measurements,
│                       #   AirQualityCalculator (ATMO), Statistics, Modele (CSV loading)
├── Vue/                # InterfaceUtilisateur: console menus and input
├── controleur/         # Authentifieur + one controller per role
├── TypeUtil/           # utility types: Coordinates, Period, TimeStamp
├── data/               # CSV datasets
├── Makefile
└── CMakeLists.txt
```

## Build and run

Requirements: a C++11 compiler (g++ or equivalent).

```bash
# with make
make
./airwatcher

# or with CMake
mkdir build && cd build
cmake ..
cmake --build .
./airwatcher
```

`make clean` removes build files. Run the executable from the project root (or via CMake, which copies `data/`) so the CSV files are found.

## Usage

At startup, enter a user ID and a password (type `quit` as ID to exit). Demo accounts:

| Role | ID | Password |
|---|---|---|
| Administrator | `admin` | `admin` |
| Agency | `agency` | `agency` |
| Company | `Provider0`, `Provider1`, … | same as ID |
| Private individual | `User0`, `User1`, … | same as ID |

Dates use the format `YYYY-MM-DD HH:MM:SS`. The data covers 2019; example area: latitude `45.5`, longitude `2.5`, radius in km.

## Data

CSV files in `data/` (`;` separator):

| File | Content |
|---|---|
| `sensors.csv` | sensor ID, latitude, longitude (99 sensors) |
| `measurements.csv` | timestamp, sensor, attribute, value (~146,000 readings) |
| `attributes.csv` | tracked pollutants: O3, SO2, NO2, PM10 |
| `cleaners.csv` | purifier, position, start and stop time |
| `providers.csv` | provider → purifier mapping |
| `users.csv` | private individual → private sensor mapping |

Demo passwords are intentionally trivial: this is an educational prototype with no secure credential storage.

## Team

Built by a team of four at INSA Lyon:

- Chema Bouzaidi
- Yessine Turki
- Hiba Amamou
- Ema Goncalves

## Status

Completed academic project (May–June 2026).
