#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>

//typedef matrix[][] matrix;


class matrix
{
    public:
        matrix();//int m, int n);
        virtual ~matrix();

        void getData();
        void show(std::string txt = "");
        //double** mul(matrix &X, matrix &Y);
        //matrix mul(matrix &X)
        //void mulThis(matrix &X, matrix &Y);
        matrix mul(matrix &X);
        void make(int m, int n);

        void printFileWA(std::string filename);
        void printFile(std::string filename);

        /// Operator overloading.
        matrix operator*(matrix &X);
        matrix operator+(matrix &X);

        /// Operator legality test functions.
        bool bMul(matrix &X, matrix &Y);
        bool bAdd(matrix &X, matrix &Y);

        int m, n;
        double** mx;

    protected:

    private:
        void makeMatrix();
        void printToFile(std::string text, std::string filename);

};



#endif // MATRIX_H
