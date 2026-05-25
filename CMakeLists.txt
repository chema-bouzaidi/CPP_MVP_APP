cmake_minimum_required(VERSION 3.10)
project(AirWatcher CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories so headers are found without relative paths in .cpp files
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/TypeUtil
    ${CMAKE_SOURCE_DIR}/Model
    ${CMAKE_SOURCE_DIR}/controleur
    ${CMAKE_SOURCE_DIR}/Vue
)

# Collect all source files
file(GLOB TYPEUTIL_SRC   "TypeUtil/*.cpp")
file(GLOB MODEL_SRC      "Model/*.cpp")
file(GLOB CTRL_SRC       "controleur/*.cpp")
file(GLOB VUE_SRC        "Vue/*.cpp")

add_executable(airwatcher
    main.cpp
    ${TYPEUTIL_SRC}
    ${MODEL_SRC}
    ${CTRL_SRC}
    ${VUE_SRC}
)

# The executable runs from the build dir; data files are relative to project root
# Add a post-build step to copy data/ if building out-of-source
if(NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    add_custom_command(TARGET airwatcher POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            $<TARGET_FILE_DIR:airwatcher>/data
        COMMENT "Copying data/ to build directory"
    )
endif()
