#ifndef MATRIX_INCLUDE_MATRIX_HPP_
#define MATRIX_INCLUDE_MATRIX_HPP_

#include <vector>



namespace teg {

    template<typename T>
    using Row = std::vector<T>;

    template<typename T>
    class Matrix {
        public:
            Matrix();
            Matrix(std::size_t size);
            Matrix(std::size_t rows, std::size_t cols);
            Matrix(std::size_t size, const T& value);
            Matrix(std::size_t rows, std::size_t cols, const T& value);

            Matrix(const Matrix& other);
            Matrix(Matrix&& other) noexcept;

            ~Matrix();

            std::size_t cols() const noexcept;
            std::size_t rows() const noexcept;

            bool empty() const noexcept;

            Row<T>& operator[](std::size_t index);
            const Row<T>& operator[](std::size_t index) const;

            Matrix& operator=(const Matrix& other);
            Matrix& operator=(Matrix&& other) noexcept;

        private:
            std::vector<Row<T>> m_storage;
    }; // !class Matrix<T>

    template<typename T>
    Matrix<T>::Matrix() :
        m_storage() {}

    template<typename T>
    Matrix<T>::Matrix(std::size_t size) :
        Matrix(size, size) {}

    template<typename T>
    Matrix<T>::Matrix(std::size_t rows, std::size_t cols) :
        Matrix(rows, cols, {}) {}

    template<typename T>
    Matrix<T>::Matrix(std::size_t size, const T& value) :
        Matrix(size, size, value) {}

    template<typename T>
    Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const T& value) :
        m_storage(rows, std::vector<T>(cols, value)) {}

    template<typename T>
    Matrix<T>::Matrix(const Matrix<T>& other) :
        m_storage(other.m_storage) {
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix<T>&& other) noexcept :
        m_storage(std::move(other.m_storage)) {}

    template<typename T>
    Matrix<T>::~Matrix() {}

    template<typename T>
    std::size_t Matrix<T>::rows() const noexcept {

        return m_storage.size();

    }

    template<typename T>
    std::size_t Matrix<T>::cols() const noexcept {

        if (m_storage.empty()) return 0;
        return m_storage[0].size();

    }

    template<typename T>
    bool Matrix<T>::empty() const noexcept {

        return m_storage.empty();

    }

    template<typename T>
    Row<T>& Matrix<T>::operator[](std::size_t index) {

        return const_cast<Row<T>&>(static_cast<const Matrix&>(*this)[index]);

    }

    template<typename T>
    const Row<T>& Matrix<T>::operator[](std::size_t index) const {

        return m_storage[index];

    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {

        if (this == &other)
            return *this;

        m_storage = other.m_storage;

        return *this;

    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {

        if (this == &other)
            return *this;

        m_storage = std::move(other.m_storage);

        return *this;

    }

} // !namespace teg

#endif // !MATRIX_INCLUDE_MATRIX_HPP_