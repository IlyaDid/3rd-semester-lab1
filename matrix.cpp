#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "matrix.hpp"
matrix::matrix(){
    m = 0;
    n = 0;
}
matrix::~matrix(){
    delete[] arr;
}
matrix::matrix(const size_t m, const size_t n){
    if(m <= 0 || n <= 0)
        throw std::runtime_error("Invalid matrix sizes");
    this->m = m;
    this->n = n;
    double buf;
    arr = new std::unordered_map<size_t, double>[m];
    for(size_t i = 0; i < m; i++){
        for(size_t j = 0; j < n; j++){
            try{
                buf = getNum<double>(-__DBL_MAX__, __DBL_MAX__);
            }catch(std::runtime_error& e){
                for(size_t i = 0; i < m; i++)
                    arr[i].clear();
                this->m = 0;
                this->n = 0;
                throw std::runtime_error(e.what());
            }
            if(fabs(buf) > 0.000001) arr[i][j] = buf;
        }
    }
}
matrix *matrix::minmax_swap() const{
    matrix *res = new matrix();
    res->m = m;
    res->n = n;
    res->arr = new std::unordered_map<size_t, double>[m];
    for(size_t i = 0; i < m; i++)
        res->arr[i] = arr[i];
    double min = __DBL_MAX__;
    double max = -__DBL_MAX__;
    for(size_t i = 0; i < m; i++){
        min = __DBL_MAX__;
        max = -__DBL_MAX__;
        for(size_t j = 0; j < n; j++){
            if(arr[i].contains(j)){
                if(arr[i][j] > max) max = arr[i][j];
                else if(arr[i][j] < min) min = arr[i][j];
            }
            else{
                if((double)0 > max) max = arr[i][j];
                else if((double)0 < min) min = arr[i][j];
            }
        }
        for(size_t j = 0; j < res->n; j++){
            if(res->arr[i].contains(j)){
                if(fabs(res->arr[i][j] - max) < 0.000001) res->arr[i][j] = min;
                else if(fabs(res->arr[i][j] - min) < 0.000001) res->arr[i][j] = max;
            }
            else{
                if(fabs((double)0 - max) < 0.000001) res->arr[i][j] = min;
                else if(fabs((double)0 - min) < 0.000001) res->arr[i][j] = max;
            }
        }
    }
    return res;
}
void matrix::print() const{
    std::cout << std::endl;
    for(size_t i = 0; i < m; i ++){
        for(size_t j = 0; j < n; j++){
            if(arr[i].contains(j))
                std::cout << arr[i][j] << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}
void matrix::summ(){
    double buf;
    std::cout << std::endl;
    for(size_t i = 0; i < m; i++){
        buf = 0;
        for(const auto& [ind, elem] : arr[i])
            buf += elem;
        sum[i] = buf;
        std::cout <<sum[i] << " ";
    }
    std::cout << std::endl;
}