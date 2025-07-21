cmake_minimum_required (VERSION 3.10...3.15)

project (Owl LANGUAGES CXX)

set (CMAKE_CONFIGURATION_TYPES Debug Release)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory ("Owl")
add_subdirectory ("Sandbox")
