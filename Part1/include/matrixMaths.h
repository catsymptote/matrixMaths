#ifndef MATRIXMATHS_H
#define MATRIXMATHS_H


#include <iostream>
#include <vector>


typedef std::vector< std::vector<double> > matrix;


class matrixMaths
{
    public:
        matrixMaths(matrix A, matrix B);
        virtual ~matrixMaths();

        void setMatrix(matrix A, int matNum);
        matrix getMatrix(int matNum);

        void show(matrix matx);

        //matrix getData(); // setMatrix()
        void show(int matNum);

        matrix mul(matrix A, matrix B);

        //std::vector<std::vector<double>> mul();



    protected:

    private:
        matrix A;
        matrix B;

        /// Use references here:
        void setA(matrix matx);
        void setB(matrix matx);
        void setC(matrix matx);
};

#endif // MATRIXMATHS_H
