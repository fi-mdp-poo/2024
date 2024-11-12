#include <iostream>

// Clase base que usa CRTP
template <typename Derived>
class Base {
public:
    // Método de la clase base que llama a un método de la clase derivada
    void interface() {
        // Se usa `static_cast` para convertir `this` a un puntero de tipo `Derived`
        // y llamar al método `implementation` de la clase derivada.
        static_cast<Derived*>(this)->implementation();
    }

    // Método opcional que puede ser sobrescrito en la clase derivada.
    void implementation() {
        std::cout << "Llamada a Base::implementation()" << std::endl;
    }
};

// Clase derivada que se pasa a sí misma como parámetro de plantilla a `Base`
class Derived : public Base<Derived> {
public:
    // Método `implementation` sobreescrito en la clase derivada
    void implementation() {
        std::cout << "Llamada a Derived::implementation()" << std::endl;
    }
};

int main() {
    Derived d;   // Crear una instancia de `Derived`
    d.interface(); // Llamar al método `interface`, que usa `CRTP` para llamar al método de `Derived`

    Base<Derived> b; // Crear una instancia de `Base<Derived>` directamente (no común en CRTP, pero ilustrativo)
    b.interface();   // Llamará a `Derived::implementation()` gracias al `static_cast`

    return 0;
}
