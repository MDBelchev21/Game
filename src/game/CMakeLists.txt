cmake_minimum_required(3.10)

project(game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(game SHARED main.cpp)
