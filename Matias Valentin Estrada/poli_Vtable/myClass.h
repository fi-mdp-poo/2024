#ifndef MYCLASS_H_INCLUDED
#define MYCLASS_H_INCLUDED

#include <iostream>

using namespace std;

class Animal{
    public:
        /// Constructores y Destructor ///
        Animal(){cout << "Constructor de oficio Animal" << endl;}
        Animal(const Animal& other){cout << "Constructor de copia Animal" << endl;}
        virtual ~Animal(){cout << "Destructor Animal" << endl;}

        /// Acciones ///
        void eat();
        virtual void makeSound(){cout << "Animal" << endl;}

        virtual Animal* clonar(){return new Animal(*this);}
};

class Dog : public Animal{
    public:
        /// Constructores y Destructor ///
        Dog(){cout << "Constructor de oficio Dog" << endl;}
        Dog(const Dog& other){cout << "Constructor de copia Dog" << endl;}
        virtual ~Dog(){cout << "Destructor Dog" << endl;}

        /// Acciones///
        void makeSound(){cout << "Guau Guau" << endl;}

        Dog* clonar()override{return new Dog(*this);}
};

class Cat : public Animal{
    public:
        /// Constructores y Destructor ///
        Cat(){cout << "Constructor de oficio Cat" << endl;}
        Cat(const Cat& other){cout << "Constructor de copia Cat" << endl;}
        virtual ~Cat(){cout << "Destructor Cat" << endl;}

        /// Acciones///
        void makeSound(){cout << "Miau" << endl;}

        Cat* clonar()override{return new Cat(*this);}
};

#endif // MYCLASS_H_INCLUDED
