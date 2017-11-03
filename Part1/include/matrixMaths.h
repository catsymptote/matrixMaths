#ifndef MATRIXMATHS_H
#define MATRIXMATHS_H


#include <vector>


typedef std::vector< std::vector<double> > matrix;


class matrixMaths
{
    public:
        matrixMaths();
        virtual ~matrixMaths();
        void show();
        //std::vector<std::vector<double>> mul();
        matrix mul();
        matrix getData();

    protected:

    private:
        matrix mat1;
        matrix mat2;
};

#endif // MATRIXMATHS_H
