#include "matrixMaths.h"

matrixMaths::matrixMaths(matrix A, matrix B)
{
    //ctor
    setMatrix(A, 0);
    setMatrix(B, 1);
}

matrixMaths::~matrixMaths()
{
    //dtor
}


matrix A;
matrix B;
matrix C;



/// Set input matrix equal class matrix
void matrixMaths::setMatrix(matrix mtrx, int matNum)
{
    if(matNum == 0)
    {
        setA(mtrx);
    }
    else if(matNum == 1)
    {
        setB(mtrx);
    }
    else if(matNum == 2)
    {
        setC(mtrx);
    }
}
void matrixMaths::setA(matrix matx)
{
    for(int i = 0; i < matx.size(); i++)
    {
        std::vector<double> tmp;
        for(int j = 0; j < matx.at(0).size(); j++)
        {
            tmp.push_back(matx.at(i).at(j));
            //this->A.at(i).at(j) = matx.at(i).at(j);
        }
        A.push_back(tmp);
    }
}
void matrixMaths::setB(matrix matx)
{
    for(int i = 0; i < matx.size(); i++)
    {
        std::vector<double> tmp;
        for(int j = 0; j < matx.at(0).size(); j++)
        {
            tmp.push_back(matx.at(i).at(j));
            //this->A.at(i).at(j) = matx.at(i).at(j);
        }
        B.push_back(tmp);
    }
}
void matrixMaths::setC(matrix matx)
{
    for(int i = 0; i < matx.size(); i++)
    {
        std::vector<double> tmp;
        for(int j = 0; j < matx.at(0).size(); j++)
        {
            tmp.push_back(matx.at(i).at(j));
            //this->A.at(i).at(j) = matx.at(i).at(j);
        }
        C.push_back(tmp);
    }
}


matrix matrixMaths::getMatrix(int matNum)
{
    if(matNum == 0)
    {
        return A;
    }
    else if(matNum == 1)
    {
        return B;
    }
    else if(matNum == 2)
    {
        return C;
    }
}


/// Display the matrix in the console for the user.
void matrixMaths::show(matrix matx)
{
    std::cout << "--------------------------------" << std::endl;
    for(int i = 0; i < matx.size(); i++)
    {
        for(int j = 0; j < matx.at(0).size(); j++)
        {
            std::cout << matx.at(i).at(j) << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------------------" << std::endl;
}





/// Return multiple of two matrices.
matrix matrixMaths::mul(matrix A, matrix B)
{
    // A(3x3)*B(3x3)=C(3x3) = C(term+term+term, term+...)
    /// m:x, n:y
    int mSize = B.size();
    int nSize = A.size();
    // Check: A[0] == B[0][0] && A[0][0] == B[0]

    matrix C;
    std::vector<double> tmp;

    double term;
    for (int m = 0; m < mSize; m++)
    {
        for (int n = 0; n < nSize; n++)
        {
            term = 0;
            for (int t = 0; t < mSize; t++)
            {
                //std::cout << "m:" << m << ", n:" << n << ", t:" << t << std::endl;
                term += A[m][t] * B[t][n];

            }
            tmp.push_back(term);
        }
        C.push_back(tmp);
        tmp.clear();

    }
    return C;
}
