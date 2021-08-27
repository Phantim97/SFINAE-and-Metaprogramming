cmake_minimum_required(VERSION 3.8)

project(MetaprogrammingAndSFINAE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17) # Set to 17 for future examples
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/MetaMath)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/Types)

add_executable(main source.cpp "MetaMath/Fraction.h")