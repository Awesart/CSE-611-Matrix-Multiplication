#include <Matrix.hpp>
#include <iostream>
#include <random>
#include <time.h>

void MatrixMultiplication(size_t dim) { 

    clock_t t; 
    std::mt19937 mt(1692);
    std::uniform_int_distribution<int> dist(0, 1999);

    std::vector<std::vector<int>> randVecA(dim, std::vector<int>(dim));    
    std::vector<std::vector<int>> randVecB(dim, std::vector<int>(dim));


    for(size_t i = 0; i < dim; i++)
        for(size_t j = 0; j < dim; j++){
            randVecA[i][j] = dist(mt);
            randVecB[i][j] = dist(mt);
        }
            
    Matrix<int> A(randVecA);
    Matrix<int> B(randVecB);
    Matrix<int> C(dim, dim);
    
    t = clock();
    C = A * B;
    t = clock() - t;

    std::cout << "The time it took to run this matrix multiplication was " << ((float)t) / CLOCKS_PER_SEC << " s \n" ;
}

int main (){
    MatrixMultiplication(2000);
}