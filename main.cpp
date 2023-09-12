#include <iostream>
#include "matrix.hpp"
int main(){
    matrix *matr, *res;
    size_t m, n;
    std::cout << "Enter matrix dimensions: ";
    m = getNum<size_t>();
    n = getNum<size_t>();
    std::cout << "Enter matrix: " << std::endl;
    try{
        matr = new matrix(m,n);
        std::cout << std::endl << "Initial matrix: ";
        matr->print();
        matr->summ();
        std::cout << std::endl << "Result matrix: ";
        res = matr->minmax_swap();
        res->print();
        res->summ();
        delete matr;
        delete res;
    }catch(std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}