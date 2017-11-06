#include "matrix.h"

#include <iostream>
#include <memory>


matrix matrixGen(int m, int n);
int main()
{
    /// Create the matrix objects
    matrix A;
    matrix B;
    matrix C;
    matrix D;
    //std::auto_ptr<matrix> A(new matrix);

    /// Get data from user.
    A.getData();
    B.getData();


    /// Do maths using the user input.
    C = A * B;
    D = A + B;

    /// Show and print to file.
    A.show("A");
    B.show("B");
    C.show("AB");
    D.show("A+B");

    /// Print to file formatted for Wolfram Alpha.
    A.printFileWA("A");
    B.printFileWA("B");
    C.printFileWA("AB");
    D.printFileWA("A+B");


    /// Automatically generated matrices.
    A = matrixGen(8, 8);
    B = matrixGen(8, 8);
    C = A * B;
    D = A + B;
    A.show("X");
    B.show("Y");
    C.show("XY");
    D.show("X+Y");
    A.printFileWA("X");
    B.printFileWA("Y");
    C.printFileWA("XY");
    D.printFileWA("X+Y");

    return 0;
}


matrix matrixGen(int m, int n)
{
    /// Make array and pointer
    double** mtx = new double*[m];
    for(int i = 0; i < m; i++)
    {
        mtx[i] = new double[n];
    }
    double counter = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
             counter += 1;
             mtx[i][j] = counter;
        }
    }
    matrix X(mtx, m, n);
    return(X);
}
