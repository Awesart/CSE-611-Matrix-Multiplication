#include <gtest/gtest.h>
#include <Matrix.hpp>

TEST(Construction, BasicConstructionTest){

    Matrix<int> a(3,3);
        
    a.setElement(0, 1, 5);

    EXPECT_EQ(a.getElement(0, 1), 5);
}

TEST(Construction, BasicVectorConstructionTest){

    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}};
        
    Matrix<int> a(vec); 

    EXPECT_EQ(a.getNumRows(), 2);
    EXPECT_EQ(a.getNumCols(), 3);

    for(int i = 0; i < a.getNumRows(); i++)
        for(int j = 0; j < a.getNumCols(); j++)
            EXPECT_EQ(a.getElement(i, j), vec[i][j]); 
}

TEST(Multiplication, BasicMultiplicationTest) {

    std::vector<std::vector<int>> vecA = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> vecB = {{1, 4}, {2, 5}, {3, 6}};
    std::vector<std::vector<int>> vecP = {{14, 32}, {32, 77}};

    Matrix<int> a(vecA);
    Matrix<int> b(vecB);
    Matrix<int> p(vecP);

    Matrix<int> c = a * b;

    EXPECT_EQ(c.getNumRows(), 2);
    EXPECT_EQ(c.getNumCols(), 2);
    EXPECT_EQ(p.getNumRows(), 2);
    EXPECT_EQ(p.getNumCols(), 2);


    for(int i = 0; i < vecP.size(); i++)
        for(int j = 0; j < vecP[i].size(); j++)
            EXPECT_EQ(c.getElement(i, j), p.getElement(i, j));

    EXPECT_TRUE(p == c);

}