#include "matrix.h"

#include <iostream>
#include <memory>


//mul(matrix &A, matrix &B);
//operator*(matrix &x, matrix &y);


int main()
{
    matrix A;
    matrix B;
    matrix C;
    //std::auto_ptr<matrix> A(new matrix);
    //std::auto_ptr<matrix> B(new matrix);
    //std::auto_ptr<matrix> C(new matrix);

    A.getData();
    B.getData();
    C.mulThis(A, B);

    A.show("A");
    B.show("B");
    C.show("AB");

    A.printFileWA(".txt");
    A.printFile(".txt");
    B.printFileWA(".txt");
    B.printFile(".txt");
    //C.printFileWA(".txt");
    C.printFile(".txt");

    return 0;
}
