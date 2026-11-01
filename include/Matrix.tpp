#include <exception>
#include <vector>
#include "Matrix.hpp"

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

    numRows_ = 0;
    numCols_ = 0;
    numRowSet_ = false;
    numColSet_ = false;
    elements_ = nullptr;

    setNumRows(numRows);
    setNumCols(numCols);

}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> &vector) {

    numRows_ = 0;
    numCols_ = 0;
    numRowSet_ = false;
    numColSet_ = false;
    elements_ = nullptr;

    size_t numRows = vector.size();
    size_t numCols = vector[0].size();

    setNumRows(numRows);
    setNumCols(numCols);

    size_t count = numRows_ * numCols_;
    for(size_t i = 0; i < vector.size(); i++)
        for(size_t j = 0; j < vector[i].size(); j++)
            elements_[i * numCols_ + j] = vector[i][j];

}

template<typename T>
void Matrix<T>::setNumRows(size_t numRows) {

    if(numColSet_){
        elements_ = allocate(numRows, numCols_);
    }

    numRows_ = numRows; 
    numRowSet_ = true;

}

template<typename T>
void Matrix<T>::setNumCols(size_t numCols) {
    if(numRowSet_){
        elements_ = allocate(numRows_, numCols);
    }

    numCols_ = numCols; 
    numColSet_ = true;
}

template <typename T>
size_t Matrix<T>::getNumRows() const noexcept{
    return numRows_;
}

template <typename T>
size_t Matrix<T>::getNumCols() const noexcept{
    return numCols_;
}


template <typename T>
std::unique_ptr<T[]> Matrix<T>::allocate(size_t numRows, size_t numCols) {

    std::unique_ptr<T[]> elements (new T[numRows * numCols]{});

    return elements;
}

template <typename T>
void Matrix<T>::setElement(int row, int col, T value)
{
    elements_[row * numCols_ + col] = value;
}

template <typename T>
T Matrix<T>::getElement(int row, int col)
{
    return elements_[row * numCols_ + col];
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other)
{
    Matrix<T> product(numRows_, other.numCols_);

    //Now utilize tiling.
    constexpr auto BLOCK = 64;
    for(size_t ib = 0; ib < numRows_; ib += BLOCK){
        for(size_t kb = 0; kb < numCols_; kb += BLOCK){
            for(size_t jb = 0; jb < other.numCols_; jb += BLOCK){

                const size_t a = std::min(ib + BLOCK, numRows_);
                const size_t mb = std::min(kb + BLOCK, numCols_);
                const size_t c = std::min(jb + BLOCK, other.numCols_);

                for(size_t i = ib; i < a; ++i){
                    for(size_t k = kb; k < mb; k++){
                        for(size_t j = jb; j < c; ++j){
                            product.elements_[i * other.numCols_ + j] += elements_[i * numCols_ + k] * other.elements_[k * other.numCols_ + j];
                        }    
                    }
                }
            }
        }
    }

    //Previous implementation
    /* 
        //KIJ implementation
        for(size_t k = 0; k < other.numRows_; k++)
            for(size_t i = 0; i < numRows_; i++)
                for(size_t j = 0; j < other.numCols_; j++)
                    product.elements_[i * other.numCols_ + j] += elements_[i * numCols_ + k] * other.elements_[k * other.numCols_ + j]; */

    return product;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &other) const
{
    //Missing dimension checks

    size_t count = numRows_ * numCols_; 

    for(size_t i = 0; i < count; i++){
        if(!(elements_[i] == other.elements_[i])){
            return false;
        }    
    }

    return true;
}
