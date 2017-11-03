#include "matrixMaths.h"

matrixMaths::matrixMaths()
{
    //ctor
}

matrixMaths::~matrixMaths()
{
    //dtor
}



matrix A;
matrix B;


void matrixMaths::setMatrix(matrix)
{

}


matrix matrixMaths::getMatrix()
{

}



/// Display the matrix in the console for the user.
void matrixMaths::show(matrix mat)
{

}


/// Return multiple of two matrices.
matrix matrixMaths::mul(matrix A, matrix B)
{
    // A(3x3)*B(3x3)=C(3x3) = C(term+term+term, term+...)
    /// m:x, n:y
    int mSize = A.at(0).size();
    int nSize = B.at(0).size();
    // Check: A[0] == B[0][0] && A[0][0] == B[0]

    matrix C;
    C.resize(mSize);

    double term;
    for (int m = 0; m < mSize; m++)
    {
        C.at(0).resize(nSize);
        for (int n = 0; n < nSize; n++)
        {
            term = 0;
            for (int t = 0; t < mSize; t++)
            {
                term += A[m][t] * B[t][n];
            }
        }
    }
    return C;
}
