#include <iostream>

using namespace std;

class Animal{
    public:
    virtual void makeSound(){
        cout << "animal" << endl;
    }
};

class Dog : public Animal{
    public:
        void makeSound(){
            cout << "Guau Guau" << endl;
        }
};

class Cat : public Animal{
    public:
        void makeSound(){
            cout << "Miau" << endl;
        }
};

int main()
{
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    cout << "Direccion de la vtable para objBase: " << animal1 << std::endl;
    cout << "Direccion de la vtable para objBase: " << *(void**)animal1 << std::endl;
    cout << "Direccion de la vtable para objDerivada: " << *(void**)animal2 << std::endl;

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;
    return 0;
}
