#include <iostream>
#include <string>

class Imprimible {      //Clase abstracta
    public:
        virtual void imprimir() const = 0; //lo hago virtual puro ya que no lo voy a utilizar en la clase base, sino en las derivadas
        virtual ~Imprimible() {}
};

class Persona : public Imprimible {
    private:
        std::string nombre;
        int edad;

    public:
        Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

        void imprimir() const override { //no pongo el virtual porque ya lo use en la clase base y eso se hereda, indico que la sobreescribo con override
            std::cout << "Persona - Nombre: " << nombre << ", Edad: " << edad << std::endl;
        }
};

class Producto : public Imprimible {
    private:
        std::string nombre;
        double precio;

    public:
        Producto(const std::string& nombre, double precio) : nombre(nombre), precio(precio) {}

        void imprimir() const override { //no pongo el virtual porque ya lo use en la clase base y eso se hereda, indico que la sobreescribo con override
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
