#include "../include/matrix.hpp"

teg::Matrix::Matrix() :
    _storage(nullptr), _rows(0), _cols(0) { }

teg::Matrix::Matrix(std::size_t size) :
    Matrix(size, size, 0) { }

teg::Matrix::Matrix(std::size_t r, std::size_t c) :
    Matrix(r, c, 0) { }

teg::Matrix::Matrix(std::size_t size, int value) :
    Matrix(size, size, value) { }

teg::Matrix::Matrix(std::size_t r, std::size_t c, int value) :
    _storage(new int*[r]), _rows(r), _cols(c) {

    for (std::size_t i = 0; i < rows(); ++i) {

        _storage[i] = new int[cols()];

        for (std::size_t j = 0; j < cols(); ++j)
            _storage[i][j] = value;

    }

}

teg::Matrix::Matrix(const Matrix& that) :
    _storage(new int*[that.rows()]), _rows(that.rows()), _cols(that.cols()) {

    for (std::size_t i = 0; i < rows(); ++i) {

        _storage[i] = new int[cols()];

        for (std::size_t j = 0; j < cols(); ++j)
            _storage[i][j] = that[i][j];

    }

}

teg::Matrix::Matrix(Matrix&& that) noexcept :
    _storage(that._storage), _rows(that.rows()), _cols(that.cols()) {

    that._storage = nullptr;
    that._rows = 0;
    that._cols = 0;

}

std::size_t teg::Matrix::rows() const noexcept {

    return _rows;

}

std::size_t teg::Matrix::cols() const noexcept {

    return _cols;

}

teg::Matrix::Row& teg::Matrix::operator[](std::size_t row) {

    return Row(_storage[row]);

}

const teg::Matrix::Row& teg::Matrix::operator[](std::size_t row) const {

    return Row(_storage[row]);

}

teg::Matrix& teg::Matrix::operator=(const Matrix& that) {

    if (this == &that)
        return *this;

    _clear();

    _rows = that.rows();
    _cols = that.cols();

    _storage = new int*[rows()];

    for (std::size_t i = 0; i < rows(); ++i) {

        _storage[i] = new int[cols()];

        for (std::size_t j = 0; j < cols(); ++j)
            _storage[i][j] = that[i][j];

    }

    return *this;

}

teg::Matrix& teg::Matrix::operator=(Matrix&& that) noexcept {

    if (this == &that)
        return *this;

    _clear();

    _storage = that._storage;
    _rows = that.rows();
    _cols = that.cols();

    that._storage = nullptr;
    that._rows = 0;
    that._cols = 0;

    return *this;

}

void teg::Matrix::_clear() {

    for (std::size_t i = 0; i < rows(); ++i)
        delete[] _storage[i];
    
    delete[] _storage;

    _storage = nullptr;
    _rows = 0;
    _cols = 0;

}

teg::Matrix::Row::Row(int* row) :
    _row(row) { }

int& teg::Matrix::Row::operator[](std::size_t index) {

    return _row[index];

}

const int& teg::Matrix::Row::operator[](std::size_t index) const {

    return _row[index];

}