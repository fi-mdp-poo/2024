#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <stdexcept>

// Declaración del template Vector
template <typename T, int cnt=10>
class Vector {
private:
    T* data;               // Apuntador a los datos
    size_t size;           // Tamaño del vector
    size_t capacity;       // Capacidad de memoria reservada

    void resize(size_t new_capacity);  // Método privado para redimensionar el vector

public:
    Vector();                               // Constructor por defecto
    explicit Vector(size_t initial_size);   // Constructor con tamaño inicial
    ~Vector();                              // Destructor

    Vector(const Vector& other);            // Constructor de copia
    Vector& operator=(const Vector& other); // Operador de asignación

    bool operator==(const Vector& other) const;  // Comparar si dos vectores son iguales
    bool operator!=(const Vector& other) const;  // Comparar si dos vectores son diferentes

    Vector operator+(const Vector& other) const; // Sumar dos vectores
    Vector& operator+=(const Vector& other);      // Operador de asignación de suma

    void push_back(T value);  // Función para agregar un elemento al final

    T& operator[](size_t index);    // Sobrecarga del operador de acceso []

    friend std::ostream& operator<< <>(std::ostream& os, const Vector<T>&); // Imprimir el vector

    size_t get_size() const;        // Obtener tamaño del vector
    size_t get_capacity() const;    // Obtener capacidad del vector
};

// Incluir la implementación del template
#include "vector.tpp"

#endif // VECTOR_H_INCLUDED
