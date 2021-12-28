# general
cmake_minimum_required(VERSION 3.1)
project(Lab09)
add_executable(Lab09 main.cpp)

# compilation proccess
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O0")
add_compile_options(${CMAKE_CXX_FLAGS})