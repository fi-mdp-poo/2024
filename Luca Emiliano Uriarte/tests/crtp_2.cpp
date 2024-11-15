#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

// Clases de figuras
class Circulo {
public:
    explicit Circulo(double radio) : radio_(radio) {}
    double calcular_area() const {
        return M_PI * radio_ * radio_;
    }
private:
    double radio_;
};

class Cuadrado {
public:
    explicit Cuadrado(double lado) : lado_(lado) {}
    double calcular_area() const {
        return lado_ * lado_;
    }
private:
    double lado_;
};

class Triangulo {
public:
    Triangulo(double base, double altura) : base_(base), altura_(altura) {}
    double calcular_area() const {
        return 0.5 * base_ * altura_;
    }
private:
    double base_;
    double altura_;
};

// Función de plantilla para procesar un contenedor genérico de figuras
template <typename Figura>
void imprimir_areas(const std::vector<Figura>& figuras) {
    for (const auto& figura : figuras) {
        std::cout << "Área: " << figura.calcular_area() << std::endl;
    }
}

// Función para procesar cada tipo almacenado en un std::tuple
template <typename Tuple, size_t Index = 0>
void procesar_tuple(const Tuple& tuple) {
    if constexpr (Index < std::tuple_size<Tuple>::value) {
        const auto& contenedor = std::get<Index>(tuple);
        imprimir_areas(contenedor);
        procesar_tuple<Tuple, Index + 1>(tuple);
    }
}

int main() {
    // Crear vectores separados para cada tipo de figura
    std::vector<Circulo> circulos = {Circulo(5.0), Circulo(2.5)};
    std::vector<Cuadrado> cuadrados = {Cuadrado(4.0), Cuadrado(3.0)};
    std::vector<Triangulo> triangulos = {Triangulo(3.0, 6.0), Triangulo(4.0, 8.0)};

    // Agrupar todos los contenedores en un std::tuple
    auto figuras = std::make_tuple(circulos, cuadrados, triangulos);

    // Procesar cada tipo en el tuple
    std::cout << "Procesando figuras:" << std::endl;
    procesar_tuple(figuras);

    return 0;
}