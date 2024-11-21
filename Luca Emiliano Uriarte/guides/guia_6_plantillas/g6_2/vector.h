#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // Para size_t
#include <stdexcept> // Para std::out_of_range

template <typename T>
class Vector {
private:
    T* data;          // Puntero a los datos del vector
    size_t size;      // Tamaño actual del vector
    size_t capacity;  // Capacidad máxima del vector

    void resize(size_t new_capacity);

public:
    // Constructor
    Vector();

    // Destructor
    ~Vector();

    // Método para redimensionar el vector
    void redimensionar(size_t new_size);

    // Sobrecarga del operador []
    T& operator[](size_t index);

    // Sobrecarga del operador [] (const)
    const T& operator[](size_t index) const;

    // Constructor de copia
    Vector(const Vector& other);

    // Constructor de copia para tipos distintos
    template <typename U>
    Vector(const Vector<U>& other);

    // Método para obtener el tamaño actual
    size_t getSize() const;
};

#include "vector.tpp" // Incluir la implementación de la plantilla

#endif // VECTOR_H