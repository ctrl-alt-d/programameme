cmake_minimum_required(VERSION 3.10...4.0)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(hello VERSION 1.0
              LANGUAGES CXX)

add_executable(hello src/main.cpp)


