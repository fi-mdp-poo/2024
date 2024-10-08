#include <iostream>
#include "myClass.h"

using namespace std;

int main()
{
    Animal* animal1 = new Dog;
    Animal* animal2 = new Cat;

    cout << endl;

    Animal* animal3 = animal1->clonar();

    cout << endl;
    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}


