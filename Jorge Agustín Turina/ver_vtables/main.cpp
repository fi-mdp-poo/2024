#include <iostream>
//No existe una forma est�ndar en C++ para acceder a la vtable, ya que no es parte del est�ndar del lenguaje.
// Sin embargo, el enfoque que mencion� (desreferenciar el primer puntero del objeto)
// se deriva de las implementaciones de compiladores como GCC y Clang. Si necesitas m�s detalles,
//  libros como "Inside the C++ Object Model" de Stanley B. Lippman son excelentes recursos
//  para entender el modelo de objetos de C++ y c�mo la vtable es gestionada por los compiladores.





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
    std::cout << "Direcci�n de la vtable: " << vtable << std::endl;

    // Imprime la direcci�n de la primera funci�n en la vtable (por ejemplo, la funci�n 'speak')
    std::cout << "Direcci�n de la funci�n 'speak': " << (void*)vtable[0] << std::endl;

    // Llama a la funci�n speak para verificar la resoluci�n polim�rfica
    obj.speak();

    return 0;
}
