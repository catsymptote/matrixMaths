#include "matrixMaths.h"

#include <iostream>
#include <vector>


int main()
{
    /// Make test matrix
    matrix A;
    matrix B;
    std::vector<double> tmp;

    tmp.push_back(1);
    tmp.push_back(2);
    A.push_back(tmp);
    tmp.clear();
    tmp.push_back(3);
    tmp.push_back(4);
    A.push_back(tmp);
    tmp.clear();

    tmp.push_back(5);
    tmp.push_back(6);
    B.push_back(tmp);
    tmp.clear();
    tmp.push_back(7);
    tmp.push_back(8);
    B.push_back(tmp);
    tmp.clear();


    matrixMaths test(A, B);

    test.show(A);
    test.show(B);

    matrix C(test.mul(A, B));

    test.show(C);

    return 0;
}
