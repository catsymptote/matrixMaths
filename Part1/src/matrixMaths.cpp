#include "matrixMaths.h"

matrixMaths::matrixMaths()
{
    //ctor
}
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



void matrixMaths::getDataFromUser(int matNum)
{
    std::cout << "Input size of A: m n> ";

    /// Get size
    int m, n;
    std::cin >> m >> n;

    //show(this->A);
    //this->A.resize(0);
    //show(A);
    matrix& matx = getMatrixRef(matNum);
    //matrix matY;
    std::vector<double> tmpVect;
    double tmpNum;

    std::cout << "Input matrix values>" << std::endl;
    for(int i = 0; i < m; i++)
    {
        std::vector<double> tmp;
        for(int j = 0; j < n; j++)
        {
            std::cin >> tmpNum;
            tmpVect.push_back(tmpNum);
        }
        matx.push_back(tmpVect);
        tmpVect.clear();
    }
    //show(matY);
}


matrix& matrixMaths::getMatrixRef(int matNum)
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
void matrixMaths::show(matrix matx, std::string txt)
{
    /*
    std::cout << "sizes:" << std::endl;
    std::cout << matx.size() << std::endl;
    std::cout << matx.at(0).size() << std::endl;
    std::cout << matx.at(1).size() << std::endl;
    */

    std::cout << "\n" << txt << std::endl;
    std::cout << "--------------------------------" << std::endl;
    for(int i = 0; i < matx.size(); i++)
    {
        for(int j = 0; j < matx.at(0).size(); j++)
        {
            std::cout << matx.at(i).at(j) << "\t";
        }
        if(i != matx.size() -1)
        {
            std::cout << "\n";
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
    int mSize, nSize, tSize;
    if(A.at(0).size() == B.at(0).size())
    {
        mSize = A.size();
        nSize = B.size();
        tSize = A.at(0).size();
    }
    else if(A.size() == B.size())
    {
        mSize = A.at(0).size();
        nSize = B.at(0).size();
        tSize = A.size();
    }
    else if(A.at(0).size() == B.size())
    {
        mSize = A.size();
        nSize = B.at(0).size();
        tSize = A.at(0).size();
    }
    else if(A.size() == B.at(0).size())
    {
        mSize = A.at(0).size();
        nSize = B.size();
        tSize = A.size();
    }

    //std::cout << "m:n:t sizes - " << mSize << ":" << nSize << ":" << tSize << std::endl;
    // Check: A[0] == B[0][0] && A[0][0] == B[0]

    matrix C;
    std::vector<double> tmp;

    double term;
    for (int m = 0; m < mSize; m++)
    {
        for (int n = 0; n < nSize; n++)
        {
            term = 0;
            //std::cout << "m:n - " << m << ":" << n << std::endl;
            for (int t = 0; t < tSize; t++)
            {
                //std::cout << "t: " << t << std::endl;
                //std::cout << "m:" << m << ", n:" << n << ", t:" << t << std::endl;
                term += A[m][t] * B[t][n];
                //std::cout << "A[m][t]: " << A[m][t] << ", B[t][n]: " << B[t][n] << std::endl;
            }
            //std::cout << "term: " << term << std::endl;
            tmp.push_back(term);
        }
        C.push_back(tmp);
        tmp.clear();

    }
    return C;
}
