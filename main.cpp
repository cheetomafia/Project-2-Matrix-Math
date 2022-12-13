#include <iostream>
#include "Matrix.h"
using namespace std;

const bool SHOW_PROMPTS = false;
const int BAR_WIDTH = 40;

void testCreate();
void testCopy();
void testAssignment();
void testAdd();
void testSubtract();
void testAssignAdd();
void testAssignSubtract();
void testMultiply();
void testKitchenSink();

void printBar(int n);

int main(void)
{
  int testCase;
  void (*testCases[]) ()
  {
    testCreate,
    testCopy,
    testAssignment,
    testAdd,
    testSubtract,
    testAssignAdd,
    testAssignSubtract,
    testMultiply,
    testKitchenSink
  };

  if(SHOW_PROMPTS) 
  {
    cout << "Matrix Operation Tests\n";
    cout << "(0) Construct\n";
    cout << "(1) Copy\n";
    cout << "(2) Assign (=)\n";
    cout << "(3) Element-Wise Addition (+)\n";
    cout << "(4) Element-Wise Subtraction (-)\n";
    cout << "(5) Assign and Add (+=)\n";
    cout << "(6) Assign and Subtarct (-=)\n";
    cout << "(7) Matrix Multiplication (*)\n";
    cout << "(8) Kitchen Sink\n";    
    cout << "Enter Selection: ";
  }
  cin >> testCase;
  testCases[testCase]();
  return 0;
}

void testCreate()
{
  cout << "Construct\n";
  printBar(BAR_WIDTH);
  
  int rows, cols;
  if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rows;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> cols;

  Matrix a(rows, cols);
  cin >> a;

  cout << "Result Construct:\n";
  cout << "Matrix A:\n";
	cout << a;
	printBar(BAR_WIDTH);
}

void testCopy()
{
  cout << "Copy\n";
  printBar(BAR_WIDTH);
  
  int rows, cols;
  
  if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rows;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> cols;

	Matrix a(rows,cols);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

  cout << "Matrix A:\n";
	cout << a;
	printBar(BAR_WIDTH);

	cout << "Result Copy:\n";
	Matrix b(a);

	cout << "Matrix B:\n";
	cout << b;
  printBar(BAR_WIDTH);

}

void testAssignment()
{
  cout << "Assignment\n";
  printBar(BAR_WIDTH);
  
  int rows, cols;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rows;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> cols;

	Matrix a(rows,cols);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

  cout << "Matrix A:\n";
	cout << a;
	printBar(BAR_WIDTH);

	cout << "Result B = A:\n";
	Matrix b = a;
	cout << "Matrix B:\n";
	cout << b;
  printBar(BAR_WIDTH);

}

void testAdd()
{
  cout << "Element-Wise Add\n";
  printBar(BAR_WIDTH);
  int rowsA, colsA, rowsB, colsB;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsA;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> colsA;

	Matrix a(rowsA,colsA);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

	if( SHOW_PROMPTS ){
		cout << "Enter Matrix B:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsB;
	if( SHOW_PROMPTS ){
		cout << "Number of cols: ";
	}
	cin >> colsB;
	
	Matrix b(rowsB,colsB);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> b;
	
	cout << "Matrix A:\n";
	cout << a;
	printBar(BAR_WIDTH);

	cout << "Matrix B:\n";
	cout << b;
  printBar(BAR_WIDTH);

  cout << "Result A + B:\n";
	cout << a+b;
  printBar(BAR_WIDTH);
}

void testSubtract()
{
  cout << "Element-wise Subtraction\n";
  printBar(BAR_WIDTH);
  int rowsA, colsA, rowsB, colsB;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsA;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> colsA;

	Matrix a(rowsA,colsA);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

	if( SHOW_PROMPTS ){
		cout << "Enter Matrix B:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsB;
	if( SHOW_PROMPTS ){
		cout << "Number of cols: ";
	}
	cin >> colsB;
	
	Matrix b(rowsB,colsB);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> b;
	
	cout << "Matrix A:\n";
	cout << a;
	printBar(BAR_WIDTH);

	cout << "Matrix B:\n";
	cout << b;
  printBar(BAR_WIDTH);

  cout << "Result A - B:\n";
	cout << a-b;
  printBar(BAR_WIDTH);
}

void testAssignAdd()
{
  cout << "Assign and Add\n";
  printBar(BAR_WIDTH);
  int rowsA, colsA, rowsB, colsB;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsA;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> colsA;

	Matrix a(rowsA,colsA);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

	if( SHOW_PROMPTS ){
		cout << "Enter Matrix B:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsB;
	if( SHOW_PROMPTS ){
		cout << "Number of cols: ";
	}
	cin >> colsB;
	
	Matrix b(rowsB,colsB);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> b;
	
	cout << "Matrix A\n";
	cout << a;
	printBar(BAR_WIDTH);

	cout << "Matrix B\n";
	cout << b;
  printBar(BAR_WIDTH);

  cout << "Result A += B:\n";
	a += b;
	cout << "Matrix A:\n";
	cout << a;
  printBar(BAR_WIDTH);
}

void testAssignSubtract()
{
  cout << "Assign and Subtract\n";
  printBar(BAR_WIDTH);
  
  int rowsA, colsA, rowsB, colsB;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsA;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> colsA;

	Matrix a(rowsA,colsA);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

	if( SHOW_PROMPTS ){
		cout << "Enter Matrix B:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsB;
	if( SHOW_PROMPTS ){
		cout << "Number of cols: ";
	}
	cin >> colsB;
	
	Matrix b(rowsB,colsB);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> b;
	
	cout << "Matrix A:\n";
	cout << a;
	printBar(BAR_WIDTH);

	cout << "Matrix B:\n";
	cout << b;
  printBar(BAR_WIDTH);

  cout << "Result A -= B:\n";
	a -= b;
	cout << "Matrix A:\n";
	cout << a;
  printBar(BAR_WIDTH);
}

void testMultiply()
{
  cout << "Matrix Multiplication\n";
  printBar(BAR_WIDTH);
  int rowsA, colsA, rowsB, colsB;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsA;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> colsA;

	Matrix a(rowsA,colsA);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

	if( SHOW_PROMPTS ){
		cout << "Enter Matrix B:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsB;
	if( SHOW_PROMPTS ){
		cout << "Number of cols: ";
	}
	cin >> colsB;
	
	Matrix b(rowsB,colsB);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> b;
	
	cout << "Matrix A:\n";
	cout << a;
  printBar(BAR_WIDTH);
  
	cout << "Matrix B:\n";
	cout << b;
  printBar(BAR_WIDTH);  

  cout << "Result C = A * B:\n";
	Matrix c = a * b;
	cout << "Matrix C:\n";
	cout << c;
  printBar(BAR_WIDTH);
}

void testKitchenSink()
{
  cout << "Kitchen Sink\n";
  printBar(BAR_WIDTH);
  
  testCreate();
  testCopy();
  testAssignment();
  testAdd();
  testSubtract();
  testAssignAdd();
  testAssignSubtract();
  testMultiply();
}

void printBar(int n)
{
  cout << std::string(n, '-') << endl;
}
