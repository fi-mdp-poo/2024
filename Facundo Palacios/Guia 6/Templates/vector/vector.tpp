#ifndef VECTOR_TPP_INCLUDED
#define VECTOR_TPP_INCLUDED

// Implementación de los métodos de la clase Vector

template <typename T, int cnt>
Vector<T, cnt>::Vector() : data(nullptr), size(0), capacity(cnt) {
    try {
        data = new T[capacity];  // Usamos cnt como la capacidad inicial
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error al crear el vector: " << e.what() << std::endl;
        throw;
    }
}

template <typename T, int cnt>
Vector<T, cnt>::Vector(size_t initial_size) : size(initial_size), capacity(initial_size) {
    try {
        data = new T[capacity];  // Reservamos memoria para la capacidad
        for (size_t i = 0; i < size; ++i) {
            data[i] = T();  // Inicializamos los elementos del vector
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error al crear el vector con tamaño inicial: " << e.what() << std::endl;
        throw;
    }
}

template <typename T, int cnt>
Vector<T, cnt>::~Vector() {
    if (data) {
        delete[] data;  // Liberamos la memoria
    }
}

template <typename T, int cnt>
Vector<T, cnt>::Vector(const Vector<T, cnt>& other) : size(other.size), capacity(other.capacity) {
    try {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];  // Copiamos los datos
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error al copiar el vector: " << e.what() << std::endl;
        throw;
    }
}

template <typename T, int cnt>
Vector<T, cnt>& Vector<T, cnt>::operator=(const Vector<T, cnt>& other) {
    if (this != &other) {
        try {
            delete[] data;  // Liberamos la memoria vieja

            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];

            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];  // Copiamos los datos
            }
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Error al copiar el vector: " << e.what() << std::endl;
            throw;
        }
    }
    return *this;
}

template <typename T, int cnt>
bool Vector<T, cnt>::operator==(const Vector<T, cnt>& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

template <typename T, int cnt>
bool Vector<T, cnt>::operator!=(const Vector<T, cnt>& other) const {
    return !(*this == other);
}

template <typename T, int cnt>
Vector<T, cnt> Vector<T, cnt>::operator+(const Vector<T, cnt>& other) const {
    Vector<T, cnt> result(size + other.size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i];
    }
    for (size_t i = 0; i < other.size; ++i) {
        result[size + i] = other.data[i];
    }
    return result;
}

template <typename T, int cnt>
Vector<T, cnt>& Vector<T, cnt>::operator+=(const Vector<T, cnt>& other) {
    size_t new_size = size + other.size;
    if (new_size > capacity) {
        resize(new_size);
    }
    for (size_t i = 0; i < other.size; ++i) {
        data[size + i] = other.data[i];
    }
    size = new_size;
    return *this;
}

template <typename T, int cnt>
void Vector<T, cnt>::push_back(T value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size++] = value;
}

template <typename T, int cnt>
T& Vector<T, cnt>::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Índice fuera de rango");
    return data[index];
}

template <typename T, int cnt>
std::ostream& operator<<(std::ostream& os, const Vector<T, cnt>& v) {
    os << "[";
    for (size_t i = 0; i < v.size; ++i) {
        os << v.data[i];
        if (i < v.size - 1) os << ", ";
    }
    os << "]";
    return os;
}

template <typename T, int cnt>
size_t Vector<T, cnt>::get_size() const {
    return size;
}

template <typename T, int cnt>
size_t Vector<T, cnt>::get_capacity() const {
    return capacity;
}

template <typename T, int cnt>
void Vector<T, cnt>::resize(size_t new_capacity) {
    try {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error al intentar redimensionar el vector: " << e.what() << std::endl;
        throw;
    }
}

#endif // VECTOR_TPP_INCLUDED

