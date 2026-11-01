cmake_minimum_required(VERSION 4.2)

include(FetchContent)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.18.0
)
FetchContent_MakeAvailable(googletest)

add_executable(matrix_tests
    MatrixTest.cpp
)

target_link_libraries(matrix_tests PUBLIC MatrixClass::MatrixClass gtest_main)
add_test(NAME matrix_tests COMMAND matrix_tests)