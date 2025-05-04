cmake_minimum_required(VERSION 3.30) 

project(BankSystem) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(BankSystem
  account.cpp 
  customer.cpp 
  main.cpp
)
