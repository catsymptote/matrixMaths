#include "matrix.h"


int m, n;       /// Size of matrix.
double **mx;    /// Pointer to matrix.


/// Constructors and destructor.
matrix::matrix(){}
/// Not in use
matrix::matrix(int m, int n)
{
    this->m = m;
    this->n = n;
}
matrix::matrix(double **mx, int m, int n)
{
    this->mx = mx;
    this->m = m;
    this->n = n;
}
matrix::~matrix()
{
    //std::cout << "DIEDIEDIE!!" << std::endl;
}


/// Get's data from the user.
void matrix::getData()
{
    std::cout << "Input matrix dimensions: m n> ";
    std::cin >> m >> n;

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
}


/// cout's the matrix (with matrix name).
void matrix::show(std::string txt)
{
    std::cout << "\n" << txt;
    std::cout << "\n--------------------------------------------------" << std::endl;
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
    std::cout << "\n--------------------------------------------------" << std::endl;
    printFile(txt);
}


/// Pseudo constructor (for the matrix).
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


/// Matrix multiplication.
matrix matrix::mul(matrix &X, matrix &Y)
{
    /// Local variables
    int m = X.m;
    int n = Y.n;
    int t = X.n;

    matrix Z;
    Z.make(m, n);

    double tmp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp = 0;
            for (int k = 0; k < t; k++)
            {
                tmp += X.mx[i][k] * Y.mx[k][j];
            }
            Z.mx[i][j] = tmp;
        }
    }
    return(Z);
}


/// Matrix addition.
matrix matrix::add(matrix &X, matrix &Y)
{
    int m = X.m;
    int n = X.n;

    matrix Z;
    Z.make(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Z.mx[i][j] = X.mx[i][j] + Y.mx[i][j];
        }
    }
    return(Z);
}


/// Operator overloading.
matrix operator+(matrix &X, matrix &Y)
{
    matrix Z;

    if(!Z.bAdd(X, Y))
    {
        std::cout << "ERROR! !(A.m != Y.m && A.n != Y.n). Matrix addition impossible." << std::endl;
        return(X);
    }

    Z = Z.add(X, Y);
    return(Z);
}

matrix operator*(matrix &X, matrix &Y)
{
    matrix Z;

    if(!Z.bMul(X, Y))
    {
        std::cout << "ERROR! A.n != Y.m. Matrix multiplication impossible." << std::endl;
        return(X);
    }

    Z = Z.mul(X, Y);
    return(Z);
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


/// Print result to file.
/// Creates string with formatted input for Wolfram Alpha (maths debugging).
void matrix::printFileWA(std::string name)
{
    std::string text;
    text += name + " = ";
    text += "[[";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::stringstream ss;
            ss << mx[i][j];
            text += ss.str();
            if(j != n-1)
                text += ", ";
        }
        if(i != m-1)
            text += "], [";
    }
    text += "]]\n";

    printToFile(text, "files/WA.txt");
}

/// Creates string of matrix operations to be saved to file.
void matrix::printFile(std::string name)
{
    std::string text;
    text += name + "\n";
    text += std::to_string(m) + "," + std::to_string(n) + "\n";

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::stringstream ss;
            ss << mx[i][j];
            text += ss.str();
            if(j != n-1)
                text += "\t";
        }
        text += "\n";
    }
    text += "\n";
    printToFile(text, "files/file.txt");
}

/// Creates the file based on string.
void matrix::printToFile(std::string text, std::string filename)
{
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << text;
    file.close();
}
