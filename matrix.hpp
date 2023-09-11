#include <unordered_map>
#ifndef MATRIX_HPP_
#define MATRIX_HPP_
class matrix{
private:
    std::unordered_map<size_t, double> *arr;
    size_t m,n;
public:
    matrix();
    ~matrix();
    matrix(const size_t m, const size_t n);
    matrix *minmax_swap() const;
    void print() const;
};
#endif