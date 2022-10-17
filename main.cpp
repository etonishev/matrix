#include <iostream>

#include "include/matrix.hpp"



int main() {

    teg::Matrix<int> m1 {};             // empty matrix
    teg::Matrix<int> m2 {3};            // matrix 3 x 3
    teg::Matrix<int> m3 {4, 4};         // matrix 4 x 4
    teg::Matrix<int> m4 {5, 10};        // matrix 5 x 5 with default value is 10
    teg::Matrix<int> m5 {6, 6, 15};     // matrix 6 x 6 with default value is 15

    teg::Matrix<int> copyMatrix { m5 };
    teg::Matrix<int> moveMatrix { std::move(copyMatrix) };

    std::cout << "There are " << moveMatrix.rows() << " rows and "
        << moveMatrix.cols() << " cols in the moveMatrix\n";

    std::cout << "Is this empty? " << std::boolalpha << moveMatrix.empty() << '\n';

    std::cout << moveMatrix[0][0] << '\n';
    moveMatrix[0][0] = -15;
    std::cout << moveMatrix[0][0] << '\n';

    m1 = moveMatrix;
    m1 = std::move(moveMatrix);

    return 0;

}