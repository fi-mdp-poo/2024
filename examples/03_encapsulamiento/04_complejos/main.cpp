// fichero main.cpp

#include "complejos.h"

int main(void)
{
    complejo c1(1.1, 2.2),        // se crean e inicializan dos complejos (constructor general)
             c2(3.3, 4.4),        // se crea un complejo con el constructor por defecto
             c4(7.5),             // se crea un complejo con el valor por defecto (0.0) del 2º argumento
             suma = c1 + c2 + c4,      // se crea un complejo a partir del resultado (constructor de copia)
             c3(suma),
             resta, producto, cociente;   // inicializados por el constructor por defecto

    // se asignan valores con los operadores sobrecargados
    resta = c1 - c2;
    producto = c1 * c2;
    cociente = c1 / c2;


    // se imprimen los números complejos con el operador << sobrecargado
    cout << c1 << ", " << c2 << ", " << c3 << ", " << c4 << endl << endl;
    cout << "\nPrimer complejo:  " << c1 << endl << endl;
    cout << "Segundo complejo: " << c2 << endl << endl;
    cout << "\nSuma:     " << suma << endl << endl;
    cout << "Resta:    " << resta << endl << endl;
    cout << "Producto: " << producto << endl << endl;
    cout << "Cociente: " << cociente << endl << endl;

    c3.SetReal(5.0);              // se fijan los valores de las partes real e imaginaria de c3
    c3.SetImag(2.0);

    // operador += sobrecargado
    c1+= c3;
    c3 = 2.7 + c2;
    cout << "\nNuevo valor de c1 al sumarle c3: " << c1 << endl << endl;
    cout << "\nNuevo valor de c3 al sumarle 2.7 a " << c2 << ": " << c3 << endl << endl << endl;

    // pre-incremento de un complejo
    cout << "\tValores de c3 y c2 antes de realizar c3 + ++c2: " << c3 << "; " << c2 << endl;
    cout << "c3 + ++c2 = " << c3 + ++c2 << endl;
    cout << "\tValores de c3 y c2 despues de la operacion: " << c3 << "; " << c2 << endl;

    // post-incremento de un complejo
    c2.SetReal(3.3);  c2.SetImag(4.4);   // valores originales de c2
    cout << "\n\n\tValores de c3 y c2 antes de realizar c3 + c2++: " << c3 << "; " << c2 << endl;
    cout << "c3 + c2++ = " << c3 + c2++ << endl;
    cout << "\tValores de c3 y c2 despues de la operacion: " << c3 << "; " << c2 << endl << endl;

    // otra forma de igualar los complejos
    c4.SetReal(c3.GetReal());
    c4.SetImag(c3.GetImag());

    // se comparan complejos con los operadores == y != sobrecargados
    if (c3==c4)
        cout << "\nLos complejos \'c3\' y \'c4\' son iguales." << endl << endl;
    else
        cout << "\nLos complejos \'c3\' y \'c4\' no son iguales." << endl << endl;

    if (suma!=resta)
        cout << "\nLos complejos \'suma\' y \'resta\' son diferentes." << endl << endl;
    else
        cout << "\nLos complejos \'suma\' y \'resta\' no son diferentes." << endl << endl;

    cout << "\n\n\nYa ha terminado." << endl << endl;

    return 0;
}
