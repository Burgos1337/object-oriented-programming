#include <iostream>
#include "Prog1.h"

using namespace Prog1;

int main() {
    struct Node *arr = nullptr;
    double *res = nullptr;
    int m, n;
    
    arr = Create_Matrix(m, n);
    if (!arr) {
       std::cout << "Incorrect data detected!" << std::endl;
       return 1;
    }
    Print_Matrix("Sourced matrix:", arr, m, n);
    
    res = Create_Vector(arr, m, n);
    if (!res) {
       std::cout << "Error in allocating memory!" << std::endl;
       return 1;
    }
    Print_Vector("Final vector:", res, m);
    
    Erase_Matrix(arr);
    delete[] res;
    return 0;
}
