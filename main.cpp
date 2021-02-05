#include <iostream>

#include "include/matrix.hpp"



int main() {

    teg::Matrix matrix(3, 3, 1);
    teg::Matrix other;

    other = std::move(matrix);

    std::cout << matrix[0][0] << '\n';

    return 0;

}