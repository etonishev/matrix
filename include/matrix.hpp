#ifndef MATRIX_INCLUDE_MATRIX_HPP_
#define MATRIX_INCLUDE_MATRIX_HPP_

#include <cstddef>



namespace teg {

    class Matrix {

    public:
        class Row {
        
        public:
            Row() = delete;
            Row(int* row);

            int& operator[](std::size_t index);
            const int& operator[](std::size_t index) const;

        private:
            int* _row;

        };

    public:
        Matrix();
        Matrix(std::size_t size);
        Matrix(std::size_t r, std::size_t c);
        Matrix(std::size_t size, int value);
        Matrix(std::size_t r, std::size_t c, int value);

        Matrix(const Matrix& that);
        Matrix(Matrix&& that) noexcept;

        std::size_t rows() const noexcept;
        std::size_t cols() const noexcept;

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

} // !namespace teg

#endif // !MATRIX_INCLUDE_MATRIX_HPP_