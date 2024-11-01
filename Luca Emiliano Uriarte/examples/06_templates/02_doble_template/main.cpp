#include <iostream>
#include "complejos.h"

using namespace std;

template <class T1, class T2> void imprime(T1 &obj1, T2 &obj2, string msg)
{
    cout << msg << obj1 << ' ' << obj2 << "\n\n";
};

int main()
{
    string msg = "Mensaje original";
    double dou = 30.17428;
    char ch = 'x';
    complejo cpx(3.14, 6.28);

    imprime(msg, dou, "string + double: ");
    imprime(ch, cpx, "caracter + complejo: ");
    imprime(cpx, msg, "complejo + string: ");
    imprime(dou, ch, "double + char: ");

    imprime(msg, msg, "string + string: ");


    return 0;
}
