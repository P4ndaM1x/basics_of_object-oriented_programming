# general
cmake_minimum_required(VERSION 3.1)
project(Lab05)

# compilation proccess
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O0")
add_compile_options(${CMAKE_CXX_FLAGS})

# create library
set(PROJECT_LINK_DIRECTORY ${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/lab05.cpp")
add_library(ProjectLibrary SHARED ${SOURCES})

# create executable
add_executable(Lab05 main.cpp)
target_link_libraries(Lab05 ProjectLibrary)