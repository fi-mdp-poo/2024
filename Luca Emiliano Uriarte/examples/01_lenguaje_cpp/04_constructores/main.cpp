#include <iostream>
#include "myClass.h"

using namespace std;

int main()
{
    myClass clase1(10, 'A', 20),                // una forma de invocar al constructor
            clase2(clase1),                     // constructor de copia
            clase3 = myClass(30, 'B', 15);      // otra forma de invocar al constructor

    clase1.SetNombre((char *)"Pedro Picapiedra");
    clase1.SetiValor2(45);
    clase3.SetNombre((char *)"Pablo Marmol");
    clase3.SetiValor2(785);

    clase2.SetNombre((char *)"Vilma Betty");
    clase2.SetiValor2(3005);
    clase2.SetcLetra('Z');

    cout << "Valores clase1 = " << clase1.GetiValor1() << ", "
         << clase1.GetiValor2() << ", " << clase1.GetcLetra()
         << ", " << clase1.GetNombre() << endl << endl;

    cout << "Valores clase2 = " << clase2.GetiValor1() << ", "
         << clase2.GetiValor2() << ", " << clase2.GetcLetra()
         << ", " << clase2.GetNombre() << endl << endl;

    cout << "Valores clase3 = " << clase3.GetiValor1() << ", "
         << clase3.GetiValor2() << ", " << clase3.GetcLetra()
         << ", " << clase3.GetNombre() << endl << endl;

    clase1 = clase3;                            // copia la direccion del puntero

    cout << "Valores clase1 = " << clase1.GetiValor1() << ", "
         << clase1.GetiValor2() << ", " << clase1.GetcLetra()
         << ", " << clase1.GetNombre() << endl << endl;

    return 0;
}
