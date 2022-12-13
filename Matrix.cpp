#include "Matrix.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <assert.h>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  makeSpace();
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      data[i][j] = 0;
    }
  }
}

Matrix::~Matrix(){ // destructor that dealocates all memory when Matrix is out of scope
  for (int i = 0; i < rows; i++){
    delete [] data[i];
  }
  delete [] data;
}
Matrix::Matrix(const Matrix& rhs) : rows(rhs.rows), cols(rhs.cols){
  makeSpace();
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      data[i][j] = rhs.data[i][j];
    }
  }
}
std::istream& operator>>(std::istream& inputStream, Matrix& rhs) {
  
  for (int i = 0; i < rhs.rows; ++i) {
    for (int j = 0; j < rhs.cols; ++j) {
      inputStream >> rhs.data[i][j];
    }
  }

  return inputStream;
}
std::ostream& operator<<(std::ostream &outStream, const Matrix& rhs) {
  
  for (int i = 0; i < rhs.rows; i++) {
    
    for (int j = 0; j < rhs.cols; j++) { // makes the 
      outStream.precision(2);
      outStream << std::setw(10) << std::fixed << rhs.data[i][j];
    }
    outStream << std::endl;
  }
  return outStream;
}

Matrix& Matrix::operator=(const Matrix& rhs)  {
  if (this == &rhs){
    return *this;
  }

  if (rows != rhs.rows || cols != rhs.cols){ //basically hard coded assert funtion
    assert(rows == rhs.rows || cols == rhs.cols);
    for( int i =0; i<rows; ++i){
      delete[] data[i];
    }
    delete[] data;

    rows = rhs.rows;
    cols = rhs.cols;
    makeSpace();
  } 

  for(int i =0; i < rows; ++i){
    for(int j = 0; j<cols;++j){
      data[i][j] = rhs.data[i][j];
    }
  }
  return *this;
}

Matrix operator+(const Matrix& rhs, const Matrix& rhs2) {
  Matrix temp(rhs); // create temporary matrix so rhs1 isnt changed
  return (temp += rhs2); // perform += operation, return sum
}

Matrix operator-(const Matrix &rhs1, const Matrix &rhs2) {
  Matrix temp(rhs1); // create temporary matrix so rhs1 isnt changed
  return(temp -= rhs2); // perform -= operation, return difference
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
  assert(rhs.rows == rows || rhs.cols == cols);
  for (int i = 0; i < rows; i++){ // go through all rows
    for(int j = 0; j < cols; j++){ // go through all columns
      data[i][j] += rhs.data[i][j]; // perform addition per piece of matrix
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs) {
  assert(rhs.rows == rows || rhs.cols == cols);
  for (int i = 0; i < rows; i++) { //go through all rows
    for (int j = 0; j < cols; j++) { // go through all columns
      data[i][j] -= rhs.data[i][j]; //perform subtraction per piece of matrix
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs) {
  //std::cout << rows;
  assert(rhs.rows != rows || rhs.cols != cols);
  Matrix temp(rows, rhs.cols);
  for(int i=0;i<temp.rows;++i){ // go through all rows
    for(int j=0;j<temp.cols;++j){ // go through all columns
      for(int k =0; k < cols;++k){ // go through rows and colums of C
        temp.data[i][j] += (data[i][k] * rhs.data[k][j]); // perform multiplication per piece
      }
    }
  }
  return(*this = temp);
}

Matrix operator*(const Matrix& rhs1, const Matrix& rhs2){
  Matrix temp(rhs1); //create temporary matrix so as to not change rhs1 or rhs2
  return(temp *= rhs2); //use *= to perform multiplication
}

void Matrix::makeSpace() { // alocates space so data can be stored
  data = new double*[rows];
  for (int i = 0; i < rows; i ++)
    data[i] = new double[cols];
}
