cmake_minimum_required(VERSION 3.28)
project(game LANGUAGES CXX)

string(TIMESTAMP PDB_TIMESTAMP "%Y%m%d%H%M%S")
set(CMAKE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/pdbs")
set(CMAKE_PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/pdbs")
set(CMAKE_PDB_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/pdbs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB sources
        *.cpp
        *.h
        *.hpp
)

add_library(game SHARED ${sources})

set_target_properties(game PROPERTIES
        PDB_NAME "game_${PDB_TIMESTAMP}"
        PDB_NAME_DEBUG "game_${PDB_TIMESTAMP}"
        COMPILE_PDB_NAME "game_${PDB_TIMESTAMP}"
        COMPILE_PDB_NAME_DEBUG "game_${PDB_TIMESTAMP}"
)

target_compile_features(game PRIVATE cxx_std_23)
target_link_libraries(game PRIVATE SFML::Graphics)
