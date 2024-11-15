#include <iostream>
#include <variant>
#include <vector>
#define PI 3.141592653589793238

using namespace std;

template <typename T> class Figura{
    public:
        double calc_area() const{
            return static_cast<const T*>(this)->calcular_area();
        }
};

class Triangulo : public Figura<Triangulo>{
    private:
        double base;
        double altura;
    public:
        Triangulo(double base, double altura) : base(base), altura(altura){}

        double calcular_area() const{
            return base*altura;
        }
};

class Cuadrado : public Figura<Cuadrado>{
    private:
        double base;
        double altura;
    public:
        Cuadrado(double base, double altura) : base(base), altura(altura){}

        double calcular_area() const{
            return (base*altura)/2;
        }
};

class Circulo : public Figura<Circulo>{
    private:
        double radio;
    public:
        Circulo(double radio) : radio(radio){}

        double calcular_area() const{
            return PI*radio*radio;
        }
};


// Definimos un tipo variante para almacenar distintos tipos de figuras
using FiguraVariant = variant<Triangulo, Cuadrado, Circulo>;

// Función que acepta un std::variant y llama al método dibujar
template <typename T>
void dibujarFigura(const T& figura){
    figura.dibujar();
}

int main(){
    vector<FiguraVariant> figuras;

    // Añadimos diferentes figuras al vector
    figuras.emplace_back(Triangulo());
    figuras.emplace_back(Cuadrado());
    figuras.emplace_back(Circulo());

    // Recorremos el vector y dibujamos cada figura
    for(const auto& figura : figuras){
        visit([](const auto& f) { calc_area(f); }, figura);
    }

    return 0;
}
