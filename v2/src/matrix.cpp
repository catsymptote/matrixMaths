#include "matrix.h"


int m, n;
double **mx;


matrix::matrix()// m, int n)// : mx(new int[m][n])
{
    //ctor
    /*
    this->m = m;
    this->n = n;
    //const int mm = m;
    //const int nn = n;
    //mx(new int[m][n]){};
    double** mtx = new double*[m];
    for(int i = 0; i < m; i++)
    {
        mtx[i] = new double[n];
    }
    mx = mtx;
    //this->mx = mtx;
    */
}


matrix::~matrix()
{
    //dtor
}


void matrix::getData()
{
    std::cout << "Input matrix dimensions: m n> ";
    std::cin >> m >> n;

    //double mat[m][n];

    /// Make array and pointer
    double** mtx = new double*[m];
    for(int i = 0; i < m; i++)
    {
        mtx[i] = new double[n];
    }
    mx = mtx;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> mx[i][j];
        }
    }
    //mx = mat;
}


void matrix::show(std::string txt)
{
    std::cout << "\n" << txt;
    std::cout << "\n----------" << std::endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << mx[i][j] << "\t";
        }
        if(i != m-1)
        {
            std::cout << "\n\n";
        }
    }
    std::cout << "\n----------" << std::endl;
}


//void matrix::mulThis(matrix &X, matrix &Y)
matrix matrix::mul(matrix &X)
{
    /// Local variables
    int m = this->m;
    int n = X.n;
    int t = this->n;

    matrix Z;
    Z.make(m, n);

    if(this->n != X.m)
    {
        std::cout << "Error. A.n != Y.m. Matrix multiplication impossible." << std::endl;
        return(Z);
    }

    //makeMatrix();
    //double ** Xmx = X.mx;
    //double ** Ymx = Y.mx;
    //std::cout << sizeof(Xmx) << std::endl;
    //std::cout << sizeof(Xmx[0]) << std::endl;

    //std::cout << "m:" << m << ", n:" << n << ", t:" << t << std::endl;
    //std::cout << "X.mx[0][0]:" << X.mx[0][0] << std::endl;
    //std::cout << "Y.mx[0][0]:" << Y.mx[0][0] << std::endl;

    double tmp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp = 0;
            //std::cout << "m:n - " << m << ":" << n << std::endl;
            for (int k = 0; k < t; k++)
            {
                //std::cout << "t: " << t << std::endl;
                //std::cout << "i:" << i << ", j:" << j << ", k:" << k << std::endl;
                tmp += mx[i][k] * X.mx[k][j];
                //std::cout << "A[m][t]: " << A[m][t] << ", B[t][n]: " << B[t][n] << std::endl;
            }
            Z.mx[i][j] = tmp;
        }
    }
    return(Z);
}


//matrix matrix::mul(matrix &X)
//{
//
//}


void matrix::makeMatrix()
{
    /// Make array and pointer
    double** mtx = new double*[m];
    for(int i = 0; i < m; i++)
    {
        mtx[i] = new double[n];
    }
    mx = mtx;
}



void matrix::printFileWA(std::string filename)
{
    std::string text;

    text += "[[";
    /*
    for(int i = 0; i < m; i++)
    {
        text += "[";
    }
    */

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //text += std::to_string(mx[i][j]);
            std::stringstream ss;
            ss << mx[i][j];
            text += ss.str();
            if(j != n-1)
                text += ", ";
        }
        if(i != m-1)
            text += "], [";
    }

    text += "]]";
    /*
    for(int i = 0; i < m; i++)
    {
        text += "]";
    }
    */

    printToFile(text, "_WA_" + filename);
}



/// Operator overloading
matrix matrix::operator*(matrix &X)
{
    //if(!bMul(X))
    //    std::cout << "Illegal matrix multiplication!" << std::endl;
    //    return;
    matrix Y;
    Y = mul(X);
    return(Y);
}

matrix matrix::operator+(matrix &X)
{
    //if(!bAdd())
    //    std::cout << "Illegal matrix addition!" << std::endl;
    //    return;

    matrix Y;
    Y.make(X.m, X.n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Y.mx[i][j] = mx[i][j] + X.mx[i][j];
        }
    }
    return(Y);
}


/// Return true if able to multiply matrices.
bool matrix::bMul(matrix &X, matrix &Y)
{
    if(X.n != Y.m)
        return false;

    return true;
}

/// Return true if able to add matrices.
bool matrix::bAdd(matrix &X, matrix &Y)
{
    if(X.m != Y.m)
        return false;
    if(X.n != Y.n)
        return false;

    return true;
}


void matrix::make(int m, int n)
{
    /// Make array and pointer
    double** mtx = new double*[m];
    for(int i = 0; i < m; i++)
    {
        mtx[i] = new double[n];
    }
    mx = mtx;
    this->m = m;
    this->n = n;
}


void matrix::printFile(std::string filename)
{
    std::string text;
    text = std::to_string(m) + "," + std::to_string(n) + "\n";

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //text += std::to_string(mx[i][j]) + "\t";
            std::stringstream ss;
            ss << mx[i][j];
            text += ss.str();
            if(j != n-1)
                text += "\t";
        }
        text += "\n";
    }
    text += "\n";
    printToFile(text, "_F_" + filename);
}


void matrix::printToFile(std::string text, std::string filename)
{
    // write string to file
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << text;
    file.close();
}
