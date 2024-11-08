#include <iostream>
#include "vector.h"

int main() {
    // Test con un vector de enteros (tamaño por defecto 10)
    Vector<int> vec_int;
    for (int i = 0; i < 15; ++i) {
        vec_int.push_back(i);  // Insertamos algunos valores
    }

    std::cout << "Vector de enteros (tamaño por defecto): " << vec_int << std::endl;

    // Test con un vector de enteros (capacidad inicial especificada)
    Vector<int, 20> vec_int_20();  // Vector con capacidad inicial de 20
    for (int i = 0; i < 10; ++i) {
        vec_int_20.push_back(i * 2);  // Insertamos algunos valores
    }
    std::cout << "Vector de enteros con capacidad inicial de 20: " << vec_int_20 << std::endl;

    // Test con un vector de flotantes (float)
    Vector<float> vec_float;
    for (float i = 0.0f; i < 5.0f; i += 0.5f) {
        vec_float.push_back(i);  // Insertamos algunos valores flotantes
    }
    std::cout << "Vector de flotantes: " << vec_float << std::endl;

    // Test con un vector de caracteres (char)
    Vector<char> vec_char;
    for (char c = 'A'; c <= 'F'; ++c) {
        vec_char.push_back(c);  // Insertamos algunos caracteres
    }
    std::cout << "Vector de caracteres: " << vec_char << std::endl;

    // Test con un vector de cadenas (string)
    Vector<std::string> vec_string;
    vec_string.push_back("Hola");
    vec_string.push_back("Mundo");
    vec_string.push_back("Template");
    std::cout << "Vector de cadenas: " << vec_string << std::endl;

    return 0;
}

