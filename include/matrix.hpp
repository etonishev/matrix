#ifndef MATRIX_INCLUDE_MATRIX_HPP_
#define MATRIX_INCLUDE_MATRIX_HPP_

#include <cstddef>



namespace teg {

    template<typename T>
    class Matrix {

    public:
        class Row {
        
        public:
            Row() = delete;
            Row(T* row);

            ~Row() = default;

            T& operator[](std::size_t index);
            const T& operator[](std::size_t index) const;

        private:
            T* _row;

        }; // !class Row

    public:
        Matrix();
        Matrix(std::size_t size);
        Matrix(std::size_t r, std::size_t c);
        Matrix(std::size_t size, const T& value);
        Matrix(std::size_t r, std::size_t c, const T& value);

        Matrix(const Matrix& that);
        Matrix(Matrix&& that) noexcept;

        ~Matrix();

        std::size_t rows() const noexcept;
        std::size_t cols() const noexcept;

        bool empty() const noexcept;

        Row& operator[](std::size_t row);
        const Row& operator[](std::size_t row) const;

        Matrix& operator=(const Matrix& that);
        Matrix& operator=(Matrix&& that) noexcept;

    private:
        void _clear();

    private:
        int** _storage;
        std::size_t _rows;
        std::size_t _cols;

    }; // !class Matrix

    template<typename T>
    Matrix<T>::Matrix() :
        _storage(nullptr), _rows(0), _cols(0) { }

    template<typename T>
    Matrix<T>::Matrix(std::size_t size) :
        Matrix(size, size, 0) { }

    template<typename T>
    Matrix<T>::Matrix(std::size_t r, std::size_t c) :
        Matrix(r, c, 0) { }

    template<typename T>
    Matrix<T>::Matrix(std::size_t size, const T& value) :
        Matrix(size, size, value) { }

    template<typename T>
    Matrix<T>::Matrix(std::size_t r, std::size_t c, const T& value) :
        _storage(new T*[r]), _rows(r), _cols(c) {

        for (std::size_t i = 0; i < rows(); ++i) {

            _storage[i] = new T[cols()];

            for (std::size_t j = 0; j < cols(); ++j)
                _storage[i][j] = value;

        }

    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix<T>& that) :
        _storage(new T*[that.rows()]), _rows(that.rows()), _cols(that.cols()) {

        for (std::size_t i = 0; i < rows(); ++i) {

            _storage[i] = new T[cols()];

            for (std::size_t j = 0; j < cols(); ++j)
                _storage[i][j] = that[i][j];

        }

    }

    template<typename T>
    Matrix<T>::Matrix(Matrix<T>&& that) noexcept :
        _storage(that._storage), _rows(that.rows()), _cols(that.cols()) {

        that._storage = nullptr;
        that._rows = 0;
        that._cols = 0;

    }

    template<typename T>
    Matrix<T>::~Matrix() {

        _clear();

    }

    template<typename T>
    std::size_t Matrix<T>::rows() const noexcept {

        return _rows;

    }

    template<typename T>
    size_t Matrix<T>::cols() const noexcept {

        return _cols;

    }

    template<typename T>
    bool Matrix<T>::empty() const noexcept {

        return _storage == nullptr;

    }

    template<typename T>
    typename Matrix<T>::Row& Matrix<T>::operator[](std::size_t row) {

        return Row(_storage[row]);

    }

    template<typename T>
    typename const Matrix<T>::Row& Matrix<T>::operator[](std::size_t row) const {

        return Row(_storage[row]);

    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& that) {

        if (this == &that)
            return *this;

        _clear();

        _rows = that.rows();
        _cols = that.cols();

        _storage = new T*[rows()];

        for (std::size_t i = 0; i < rows(); ++i) {

            _storage[i] = new T[cols()];

            for (std::size_t j = 0; j < cols(); ++j)
                _storage[i][j] = that[i][j];

        }

        return *this;

    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix<T>&& that) noexcept {

        if (this == &that)
            return *this;

        _clear();

        std::swap(_storage, that._storage);
        std::swap(_rows, that._rows);
        std::swap(_cols, that._cols);

        return *this;

    }

    template<typename T>
    void Matrix<T>::_clear() {

        for (std::size_t i = 0; i < rows(); ++i)
            delete[] _storage[i];

        delete[] _storage;

        _storage = nullptr;
        _rows = 0;
        _cols = 0;

    }

    template<typename T>
    Matrix<T>::Row::Row(T* row) :
        _row(row) { }

    template<typename T>
    T& Matrix<T>::Row::operator[](std::size_t index) {

        return _row[index];

    }

    template<typename T>
    const T& Matrix<T>::Row::operator[](std::size_t index) const {

        return _row[index];

    }

} // !namespace teg

#endif // !MATRIX_INCLUDE_MATRIX_HPP_