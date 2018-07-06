cmake_minimum_required(VERSION 3.2)
project(lab3)

set(CMAKE_CXX_STANDARD 11)

include_directories($ENV{TOOLS_INCLUDE} ${CMAKE_SOURCE_DIR}/include)

#include(ExternalData)

set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#set(ExternalData_URL_TEMPLATES
#    "file://src/skafferi.dat"
#)

# Om Debug mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Debug mode
    message("Debug mode")
    add_definitions(-DDEBUG)
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Release mode.
    message("Release mode")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

set(SRC_LIST
        src/main.cpp
        src/Vehicle.h src/Submarine.h src/RaceCar.h src/SpaceShip.h
)

set(PWR_SRC
        pwrSRC/FuelCell.h pwrSRC/FuelCell.cpp
        pwrSRC/GasTurbine.h pwrSRC/GasTurbine.cpp
        pwrSRC/FuelCell.h
        pwrSRC/PowerSource.h
        pwrSRC/PowerSourceAdapters.h pwrSRC/PowerSourceAdapters.cpp
        pwrSRC/V8Classic.h pwrSRC/V8Classic.cpp
)


add_executable(${PROJECT_NAME} ${SRC_LIST} ${PWR_SRC})




