cmake_minimum_required(VERSION 4.2)

set(This MatrixMul)

project(${This} VERSION 1.0.0 LANGUAGES CXX)

option(BUILD_TEST "Builds test for the Matrix Multiplication" ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(src)

if(BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()