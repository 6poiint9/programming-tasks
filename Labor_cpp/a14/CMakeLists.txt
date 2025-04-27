#cmake_minimum_required(VERSION 3.28.0)
#project(MathDemo LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_EXTENSIONS OFF)

#-----------------------

cmake_minimum_required(VERSION 3.28)
project(ModularApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to use Clang (optional if already default)
# set(CMAKE_CXX_COMPILER clang++)

# Add your executable
add_executable(ModularApp
    Employee.cppm
    Worker.cppm
    Manager.cppm
    main.cpp
)



