#include <iostream>
#include <cstdlib>


//La sobrecarga del operador new no afecta directamente a las vtables.
//La vtable se genera autom�ticamente por el compilador si tienes m�todos virtuales.
//Sobrecargar el operador new solo cambia la forma en que se asigna la memoria, pero no modifica
//el mecanismo de las vtables. Las vtables se generan y gestionan autom�ticamente para cada clase con
//m�todos virtuales, independientemente de c�mo se asigna la memoria.

// Clase base A con sobrecarga del operador new y herencia virtual
class A {
public:
    // Sobrecarga del operador new para la clase A
    void* operator new(size_t size) {
        std::cout << "Sobrecargando operador new en la clase A para tama�o: " << size << " bytes\n";
        void* p = std::malloc(size);
        if (!p) {
            throw std::bad_alloc();
        }
        return p;
    }

    A() { std::cout << "Constructor de A\n"; }
    virtual void print() const {
        std::cout << "Clase A\n";
    }
};

// Clase derivada B con herencia virtual
class B : virtual public A {
public:
    B() { std::cout << "Constructor de B\n"; }
    void print() const override {
        std::cout << "Clase B\n";
    }
};

int main() {
    // Asignaci�n de memoria utilizando el operador new sobrecargado en la clase A
    A* obj = new B();  // Aqu� se llama a la sobrecarga de new en la clase A
    obj->print();

    return 0;
}
