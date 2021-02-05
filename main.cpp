#include <iostream>

#include "include/matrix.hpp"



int main() {

    teg::Matrix<int> matrix(3, 3);

    matrix[1][1] = 7;

    for (std::size_t i = 0; i < matrix.rows(); ++i) {

        for (std::size_t j = 0; j < matrix.cols(); ++j)
            std::cout << matrix[i][j] << ' ';

        std::cout << '\n';

    }


    return 0;

}