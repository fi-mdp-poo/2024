#include <iostream>
#include <math.h>
#include "complejos.h"

using namespace std;

/***  Sobrecarga de un template  ***/
template <class T> T potencia(T obj1)                           // un solo parametro
{
   	return obj1*obj1;             // eleva al cuadrado
};

template <class T1, class T2> T1 potencia(T1 base, T2 expon)    // dos parametros genericos
{
    T1 result;
    result = pow(base, expon);

    return result;
}

template <class T1> T1 potencia(T1 base, int exp)               // un parametro generico y un int
{
    T1 result = base;
    for(int loop=1; loop<exp; loop++)
    {
        result = result * base;
    }

    return result;
}
/***   fin sobrecarga de un template   ***/

/***   Función genérica   ***/
template <class T> T suma(T par1, T par2)
{
    return (par1 + par2);
}

/*** Especialización explícita para el tipo int ***/
int suma(int par1, int par2)
{
    return (par1 * par2);
}

int main()
{
    double valor1 = 2.3,
           cuadrado, cubo;

    cuadrado = potencia(valor1);
    cubo = potencia(valor1, 3);
    cout << "El cuadrado de " << valor1 << " es = " << cuadrado << "\n";
    cout << "El cubo de " << valor1 << " es = " << cubo << "\n";
    cuadrado = potencia(valor1, 4);
    cout << "La cuarta potencia de " << valor1 << " es = " << cuadrado << "\n\n\n";

    complejo cpx(3.14, 6.28),
             resultado;
    resultado = potencia(cpx);
    cout << "El cuadrado de " << cpx << " es = " << resultado << "\n";
    resultado = potencia(cpx, 3);
    cout << "El cubo de " << cpx << " es = " << resultado << "\n\n\n";

    resultado = suma(cpx, cpx);                 // función genérica
    cout << "Resultado de la suma de " << cpx << " y " << cpx << " es = " << resultado << " OK!\n";
    int sum;
    sum = suma(3, 4);                          // función especializada
    cout << "Resultado de la suma de 3 y 4 es = " << sum << " ERROR!!\n\n";

    return 0;
}





