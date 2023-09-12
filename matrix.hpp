#include <unordered_map>
#include <limits>
#include <cstring>
#ifndef MATRIX_HPP_
#define MATRIX_HPP_
class matrix{
private:
    std::unordered_map<size_t, double> *arr;
    std::unordered_map<size_t, double> sum;
    size_t m,n;
public:
    matrix();
    ~matrix();
    matrix(const size_t m, const size_t n);
    matrix *minmax_swap() const;
    void print() const;
    void summ();
};
template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()){
    T a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof()) // обнаружен конец файла
            throw std::runtime_error("Failed to read number: EOF");
        else if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
            throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
        else if (std::cin.fail()) { // прочие ошибки (неправильный формат ввода)
            std::cin.clear(); // очищаем флаги состояния потока
        // игнорируем все символы до конца строки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You are wrong; repeat please!" << std::endl;
    }
    else{
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (a >= min && a <= max) // если число входит в заданный диапазон
            return a;
    }
    }
}
#endif