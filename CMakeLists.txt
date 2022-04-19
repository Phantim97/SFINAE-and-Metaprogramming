cmake_minimum_required(VERSION 3.8)

project(MetaprogrammingAndSFINAE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/MetaMath)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/Types)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/ScopedTimer)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/Recursive Metaprogramming")
include_directories(${CMAKE_CURRENT_BINARY_DIR}/Concepts)

add_executable(main source.cpp)
