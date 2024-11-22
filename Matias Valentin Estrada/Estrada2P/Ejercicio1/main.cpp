#include <iostream>
#include <string>

template <typename T>
class Imprimible {
    public:
        void imprimir() const {
            static_cast<const T*>(this)->imprimirImpl();
        }
    protected:
        ~Imprimible() = default;
};

// Clase derivada para Persona
class Persona : public Imprimible<Persona> {
    private:
        std::string nombre;
        int edad;

    public:
        Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

        void imprimirImpl() const {
            std::cout << "Persona - Nombre: " << nombre << ", Edad: " << edad << std::endl;
        }
};

// Clase derivada para Producto
class Producto : public Imprimible<Producto> {
    private:
        std::string nombre;
        double precio;

    public:
        Producto(const std::string& nombre, double precio) : nombre(nombre), precio(precio) {}

        void imprimirImpl() const {
            std::cout << "Producto - Nombre: " << nombre << ", Precio: $" << precio << std::endl;
        }
};

int main(){
    Persona p("Juan Perez", 30);
    Producto prod("Laptop", 999.99);
    p.imprimir();
    prod.imprimir();
    return 0;
}
