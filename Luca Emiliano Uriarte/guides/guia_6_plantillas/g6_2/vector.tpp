#ifndef VECTOR_TPP
#define VECTOR_TPP

#include <algorithm> // Para std::copy

template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::resize(size_t new_capacity) {
    if (new_capacity > capacity) {
        T* new_data = new T[new_capacity];
        if (data) {
            std::copy(data, data + size, new_data);
            delete[] data; // Liberar memoria del array viejo
        }
        data = new_data;
        capacity = new_capacity;
    }
}

template <typename T>
void Vector<T>::redimensionar(size_t new_size) {
    resize(new_size);
    size = new_size; // Actualizamos el tamaño
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return data[index];
}

template <typename T>
Vector<T>::Vector(const Vector& other) : data(nullptr), size(other.size), capacity(other.capacity) {
    if (capacity > 0) {
        data = new T[capacity];
        std::copy(other.data, other.data + size, data);
    }
}

template <typename T>
template <typename U>
Vector<T>::Vector(const Vector<U>& other) : data(nullptr), size(other.size), capacity(other.capacity) {
    if (capacity > 0) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<T>(other[i]); // Conversión de tipos
        }
    }
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

#endif // VECTOR_TPP