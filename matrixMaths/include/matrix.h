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
        double** mul(matrix &X, matrix &Y);
        void mulThis(matrix &X, matrix &Y);

        void printFileWA(std::string filename);
        void printFile(std::string filename);

        int m, n;
        double** mx;

    protected:

    private:
        void makeMatrix();
        void printToFile(std::string text, std::string filename);

};



#endif // MATRIX_H
