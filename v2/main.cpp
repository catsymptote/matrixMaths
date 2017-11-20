#include "matrix.h"

#include <iostream>
//#include <memory>


matrix matrixGen(int m, int n);
int main()
{
    /// Create the matrix pointers.
    matrix *A;
    matrix *B;
    matrix *C;
    matrix *D;
    matrix *E;
    //matrix D;

    /// Create the objects pointed to on the heap.
    A = new matrix;
    B = new matrix;
    C = new matrix;
    D = new matrix;
    E = new matrix;
    //std::auto_ptr<matrix> A(new matrix);

    /// Get data from user.
    A->getData();
    B->getData();


    /// Do maths using the user input.
    *C = *A * *B;
    *D = *A + *B;
    *E = *A - *B;

    /// Show and print to file.
    A->show("A");
    B->show("B");
    C->show("AB");
    D->show("A+B");
    E->show("A-B");

    /// Print to file formatted for Wolfram Alpha.
    A->printFileWA("A");
    B->printFileWA("B");
    C->printFileWA("AB");
    D->printFileWA("A+B");
    E->printFileWA("A-B");



    /// Example with automatically generated matrices.
    *A = matrixGen(8, 8);
    *B = matrixGen(8, 8);
    *C = *A * *B;
    *D = *A + *B;
    *E = *A - *B;
    A->show("X");
    B->show("Y");
    C->show("XY");
    D->show("X+Y");
    E->show("X-Y");
    A->printFileWA("X");
    B->printFileWA("Y");
    C->printFileWA("XY");
    D->printFileWA("X+Y");
    E->printFileWA("X-Y");

    /// Delete (run destructor) of objects on the heap.
    delete A;
    delete B;
    delete C;
    delete D;

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
