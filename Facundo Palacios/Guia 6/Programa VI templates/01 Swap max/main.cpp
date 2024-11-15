#include <iostream>
#include "complejos.h"

using namespace std;

// Función que intercambia los valores de los parámetros
template <class Tsw> void swapargs(Tsw &a, Tsw &b)
{
    Tsw temp;
    temp = a;
    a = b;
    b = temp;
};

// Función que retorna el máximo de los parámetros
template <class T> T maximo(T x, T y)
{
   return (x > y) ? x : y;
};

// Función sobrecargada y específica
complejo maximo(complejo x, complejo y)
{
    double aux1, aux2;

    aux1 = x.GetReal()*x.GetReal() + x.GetImag()*x.GetImag();
    aux2 = y.GetReal()*y.GetReal() + y.GetImag()*y.GetImag();

    return (aux1 > aux2) ? x : y;
}

int main()
{
    int i = 10,
        j = 20;
    double x = 30.1,
           y = 23.3;
    char a = 'x',
         b = 'z';
    complejo c1(2, 3),
             c2(4, 5);

    cout << "Original i, j: " << i << ' ' << j << '\n';
    cout << "Original x, y: " << x << ' ' << y << '\n';
    cout << "Original a, b: " << a << ' ' << b << '\n';
    cout << "Original c1, c2: " << c1 << ' ' << c2 << '\n';

    swapargs(i, j);         // swap integers
    swapargs(x, y);         // swap floats
    swapargs(a, b);         // swap chars
    swapargs(c1, c2);       // swap complejos

    cout << "\nSwapped i, j: " << i << ' ' << j << '\n';
    cout << "Swapped x, y: " << x << ' ' << y << '\n';
    cout << "Swapped a, b: " << a << ' ' << b << '\n';
    cout << "Swapped c1, c2: " << c1 << ' ' << c2 << '\n';

    cout << "\n\nMaximo entre " << i << " y " << j << " = " << maximo(i, j);
    cout << "\n\nMaximo entre " << x << " y " << y << " = " << maximo(x, y);
    cout << "\n\nMaximo entre '" << a << "' y '" << b << "' = '" << maximo(a, b) << "'\n\n";
    cout << "\n\nMaximo entre '" << c1 << "' y '" << c2 << "' = " << maximo(c1, c2) << "\n\n";

    return 0;
}
