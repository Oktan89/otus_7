#include "lib.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "sparse_matrix.h"



TEST(testVersionGoogle, ValidVersion) {

  EXPECT_GT(version(), 0);
}

TEST(testSparseMatrix, MatrixZeroSize)
{
  otus::SparseMatrix<int, -1> matrix;
  EXPECT_TRUE(matrix.size() == 0);
  auto a = matrix[0][0];
  EXPECT_TRUE(a == -1);
  EXPECT_TRUE(matrix.size() == 0);
}

TEST(testSparseMatrix, Matrix2D)
{
  otus::SparseMatrix<int, -1> matrix;

  matrix[100][100] = 314;
  EXPECT_TRUE(matrix[100][100] == 314);
  EXPECT_TRUE(matrix.size() == 1);
}

TEST(testSparseMatrix, Matrix3D)
{
  otus::SparseMatrix<int, -1> matrix;

  matrix[100][100][100] = 314;
  EXPECT_TRUE(matrix[100][100][100] == 314);
  EXPECT_TRUE(matrix.size() == 1);
}

TEST(testSparseMatrix, Matrix4D)
{
  otus::SparseMatrix<int, -1> matrix;

  matrix[100][100][100][100] = 314;
  EXPECT_TRUE(matrix[100][100][100][100] == 314);
  EXPECT_TRUE(matrix.size() == 1);
}

TEST(testSparseMatrix, MatrixAssignment)
{
  otus::SparseMatrix<int, -1> matrix;

  ((matrix[100][100] = 314) = 0) = 217;
  EXPECT_TRUE(matrix[100][100] == 217);
  EXPECT_TRUE(matrix.size() == 1);
}

TEST(testSparseMatrix, MatrixClear)
{
  otus::SparseMatrix<int, -1> matrix;
  EXPECT_TRUE(matrix.size() == 0);
  ((matrix[100][100] = 314) = 0) = 217;
  EXPECT_TRUE(matrix.size() == 1);
  matrix.clear();
  EXPECT_TRUE(matrix.size() == 0);
}

TEST(testSparseMatrix, MatrixDOOMIterator)
{
  otus::SparseMatrix<int> matrix;
  constexpr int size = 10;
  for (int i = 0, j = size-1; i < size; ++i, j = size-1-i)
    {
        matrix[i][i] = i;
        matrix[i][j] = j;
    }
  EXPECT_TRUE(matrix.size() == 18);
  
  for(auto& [a, v] : matrix)
      v = 666;
 
  EXPECT_TRUE(matrix[5][5] == 666);
}
