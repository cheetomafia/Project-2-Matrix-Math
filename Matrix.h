#ifndef MATRIX_H__
#define MATRIX_H__

#include <iostream>

class Matrix
{
// Overload <<
friend std::ostream& operator<<(std::ostream&, const Matrix&);
// Overload >>
friend std::istream& operator>>(std::istream&, Matrix&);
public:
  
  Matrix(int rows, int cols);
  ~Matrix();
  Matrix(const Matrix&);
  
  // all equal operators that need to be overloaded
  Matrix& operator=(const Matrix&);

  Matrix& operator+=(const Matrix&);

  Matrix& operator-=(const Matrix&);

  Matrix& operator*=(const Matrix&);

  



private:

  int rows;
  int cols;
  double** data;
  void makeSpace();


};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);

#endif
