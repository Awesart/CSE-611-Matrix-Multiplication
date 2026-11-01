add_library(matrixclass STATIC)
add_library(MatrixClass::MatrixClass ALIAS matrixclass)

target_include_directories(matrixclass PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")

add_executable(matrix MatrixMultiplication.cpp)