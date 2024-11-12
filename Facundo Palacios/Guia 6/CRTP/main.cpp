#include <iostream>

// Clase base que usa CRTP
template <typename Derived>
class Base {
public:
    // M�todo de la clase base que llama a un m�todo de la clase derivada
    void interface() {
        // Se usa `static_cast` para convertir `this` a un puntero de tipo `Derived`
        // y llamar al m�todo `implementation` de la clase derivada.
        static_cast<Derived*>(this)->implementation();
    }

    // M�todo opcional que puede ser sobrescrito en la clase derivada.
    void implementation() {
        std::cout << "Llamada a Base::implementation()" << std::endl;
    }
};

// Clase derivada que se pasa a s� misma como par�metro de plantilla a `Base`
class Derived : public Base<Derived> {
public:
    // M�todo `implementation` sobreescrito en la clase derivada
    void implementation() {
        std::cout << "Llamada a Derived::implementation()" << std::endl;
    }
};

int main() {
    Derived d;   // Crear una instancia de `Derived`
    d.interface(); // Llamar al m�todo `interface`, que usa `CRTP` para llamar al m�todo de `Derived`

    Base<Derived> b; // Crear una instancia de `Base<Derived>` directamente (no com�n en CRTP, pero ilustrativo)
    b.interface();   // Llamar� a `Derived::implementation()` gracias al `static_cast`

    return 0;
}
