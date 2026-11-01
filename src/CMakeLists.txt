add_library(matrixclass INTERFACE)
add_library(MatrixClass::MatrixClass ALIAS matrixclass)

target_include_directories(matrixclass INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../include")

add_executable(matrix MatrixMultiplication.cpp)

target_link_libraries(matrix PRIVATE MatrixClass::MatrixClass)