# Project-2-Matrix-Math
Project 2
===
This repl will help test and submit your Project 2.
Please follow the project details document for implementation. 

The main file should not be modified. It has been created to test many different cases. 
The cases may seem repetitive but it is intentional to help diagnose each test case. 

Input for Tests
===
1. Test Case Number
2. Matrices Input Values 
   rows, cols
   data
3. Repeat 2 based on Test Case

Be sure to read read function in the main to understand the inputs and expected outputs. 


Matching Column Width and Precision
===
The test cases require exact mataches and have been formatted in a specific column width and number precision.
Make use out the following:

* output.precision(2)
* output << setw(10) << fixed << value

Where output is an ostream and value is a value to be printed. 

Assertion
===
Assert is used in this project to test that matrix sizes are correct for the operation. If the sizes are not correct the progrom should assert and exit.
To use assert statements, include:
<br><br> ***#include <assert.h\>***

Syntax for using assert statement:
assert(expression)
If the expression evaluates to false then an assertion is raied and the program terminates.

Test cases 9 and 10 will test your assertion in various matrix operations.

Memory Leaks
===
You need to make sure that you are properly deallocating dynamic memory when appropriate. You WILL be graded on your ability to provided leak-free code.

To make sure that you do not have any memory leaks, memcheck.bash has been provided to test this.
This bash scipt uses valgrind to run your program and check memory for leaks. 
Below is how to use the memcheck.bash program. 

* Open Shell
* `ls -la`
* Confirm that memcheck.bash is executable, privledges should be -rwxr-xr-x
* If privledges are not correct run chmod +x memcheck.bash
* In files menu, upper right click three dots and then show hidden files
* Open replit.nix
* Make sure pkgs.valgrind-light is in the list
* `./memcheck.bash`
* If you get "Permission denied" run `chmod +x ./memcheck.bash`
* Leak-free reads something like "in use at exit: 0 bytes in 0 blocks"
* If you have a leak you will see something like "in use at exit: 1,648 bytes in 69 blocks" and "definitely lost: 408 bytes in 18 blocks"
