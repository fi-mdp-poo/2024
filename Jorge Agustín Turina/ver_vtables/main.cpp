#include <iostream>
//No existe una forma estándar en C++ para acceder a la vtable, ya que no es parte del estándar del lenguaje.
// Sin embargo, el enfoque que mencioné (desreferenciar el primer puntero del objeto)
// se deriva de las implementaciones de compiladores como GCC y Clang. Si necesitas más detalles,
//  libros como "Inside the C++ Object Model" de Stanley B. Lippman son excelentes recursos
//  para entender el modelo de objetos de C++ y cómo la vtable es gestionada por los compiladores.





class Base {
public:
    virtual void speak() {
        std::cout << "Base::speak()" << std::endl;
    }
    virtual ~Base() {}
};

class Derived : public virtual Base {
public:
    void speak() override {
        std::cout << "Derived::speak()" << std::endl;
    }
};

class FurtherDerived : public Derived {
public:
    void speak() override {
        std::cout << "FurtherDerived::speak()" << std::endl;
    }
};

int main() {
    FurtherDerived obj;

    // Accedemos al puntero de la vtable del objeto
    // Esto toma el primer puntero del objeto, que es el puntero a la vtable
    uintptr_t* vtable = *reinterpret_cast<uintptr_t**>(&obj);

    // Imprime el puntero a la vtable
    std::cout << "Dirección de la vtable: " << vtable << std::endl;

    // Imprime la dirección de la primera función en la vtable (por ejemplo, la función 'speak')
    std::cout << "Dirección de la función 'speak': " << (void*)vtable[0] << std::endl;

    // Llama a la función speak para verificar la resolución polimórfica
    obj.speak();

    return 0;
}
