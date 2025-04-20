cmake_minimum_required(VERSION 3.28.0)

# Project name 
project(MathDemo LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)


# add execuables 
add_executable(MathDemo Employee.cpp main.cpp Manager.cpp Worker.cpp)

