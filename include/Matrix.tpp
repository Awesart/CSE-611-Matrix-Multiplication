#include "Matrix.hpp"
#include <exception>

template<typename T>
Matrix<T>::Matrix(){
    numRows_ = 0;
    numCols_ = 0;
    numRowSet_ = false;
    numColSet_ = false;
    elements_ = nullptr;
}

template<typename T>
Matrix<T>::Matrix(size_t numRows, size_t numCols){
    setNumRows(numRows);
    setNumCols(numCols);

}

template<typename T>
void Matrix<T>::setNumRows(size_t numRows) {

    if(numColSet_){
        allocate(numRows, numCols_);
    }

    numRows_ = numRows; 
    numRowSet_ = true;

}

template<typename T>
void Matrix<T>::setNumCols(size_t numCols) {
    if(numRowSet_){
        allocate(numRows_, numCols);
    }

    numCols_ = numCols; 
    numColSet_ = true;
}

template <typename T>
T* Matrix<T>::allocate(size_t numRows, size_t numCols) {

    T* elements = new T[numRows * numCols];

    return T;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other)
{
    return Matrix<T>();
}
