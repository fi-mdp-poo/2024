#include <iostream>
#include "vector.h"

int main() {
    Vector<int> v;
    v.redimensionar(5);
    v[0] = 10;
    v[1] = 20;
    std::cout << "v[0]: " << v[0] << std::endl; // Acceso
    std::cout << "v[1]: " << v[1] << std::endl; // Acceso

    try {
        std::cout << v[5] << std::endl; // Intento de acceso fuera de rango
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl; // Manejo del error
    }

    return 0;
}
