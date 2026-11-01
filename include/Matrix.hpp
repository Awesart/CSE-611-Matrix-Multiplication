#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <memory>

template<typename T>
class Matrix{

    public:
        size_t numRows_;
        size_t numCols_;
        bool numRowSet_;
        bool numColSet_;
        std::unique_ptr<T> elements_;

        void setNumRows(size_t numRows);
        void setNumCols(size_t numCols);
        T* allocate(size_t numRows_, size_t numCols_);

        Matrix<T>();
        Matrix<T>(size_t numRows , size_t numCols);
        
        Matrix<T> operator*(const Matrix<T> &other);

};

#endif