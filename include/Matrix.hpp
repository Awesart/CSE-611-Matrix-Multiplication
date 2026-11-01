#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <memory>
#include <vector>

template<typename T>
class Matrix{

    public:

        void setNumRows(size_t numRows);
        void setNumCols(size_t numCols);
        size_t getNumRows() const noexcept;
        size_t getNumCols() const noexcept;
        std::unique_ptr<T[]> allocate(size_t numRows_, size_t numCols_);

        void setElement(int row, int col, T value);
        T getElement(int row, int col);

        Matrix<T>();
        Matrix<T>(size_t numRows , size_t numCols);
        Matrix<T>(std::vector<std::vector<T>> &vector);
        Matrix<T> operator*(const Matrix<T> &other);
        bool operator== (const Matrix<T> &other) const;

    private:
        size_t numRows_;    
        size_t numCols_;
        bool numRowSet_;
        bool numColSet_;
        std::unique_ptr<T[]> elements_;

};

#include<Matrix.tpp>

#endif