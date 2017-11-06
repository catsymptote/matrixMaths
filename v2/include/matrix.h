#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>


class matrix
{
    public:
        int m, n;       /// Matrix dimensions
        double** mx;    /// Matrix pointers

        /// Constructors and destructor.
        matrix();
        matrix(int m, int n);
        matrix(double **mx, int m, int n);
        virtual ~matrix();

        void getData();                         /// Get matrix data from user.
        void show(std::string txt = "");        /// Display the matrix to the user.

        void printFile(std::string name);       /// Print matrix to file.
        void printFileWA(std::string name);     /// Print Wolfram Alpha format to file.

    private:
        matrix mul(matrix &X, matrix &Y);       /// Matrix multiplication.
        matrix add(matrix &X, matrix &Y);       /// Matrix addition.

        bool bMul(matrix &X, matrix &Y);        /// Matrix multiplication legality checker.
        bool bAdd(matrix &X, matrix &Y);        /// Matrix addition legality checker.

        void printToFile(std::string text, std::string filename);   /// Create file from string.

        void make(int m, int n);    /// Make the (local) matrix based on size inputs.

    /// (Friendly) operator overloading.
    friend matrix operator+(matrix &X, matrix &Y);
    friend matrix operator*(matrix &X, matrix &Y);
};

#endif // MATRIX_H
