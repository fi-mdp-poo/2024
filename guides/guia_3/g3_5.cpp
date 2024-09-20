#include <iostream>
#include "racional.h"
using namespace std;

int main()
{
    CRacional a, b(3, 7), c;
    int d = 3;
    cout << "a: "; cin >> a;
    c = a + b;
    c += b;
    cout << c << endl;
    c = a + b; // equivale a: c = a.operator+(b)
    cout << c << endl;
    c = b + a; // equivale a: c = b.operator+(a)
    cout << c << endl;
    c = a + static_cast<CRacional>(d);
    cout << c << endl;
    c = static_cast<CRacional>(d) + a;
    cout << c << endl;
    double x = 2.0;
    c = x + a;
    cout << c << endl;
    if (a == b) cout << "a es igual a b\n";
    if (a < b) cout << "a es menor que b\n";
    if (a > b) cout << "a es mayor que b\n";
    if (!a) cout << "racional nulo\n";
    c = ++a;
    cout << "c = " << c << endl;
    cout << "a = " << a << endl;
    c = a++;
    cout << "c = " << c << endl;
    cout << "a = " << a << endl;
    c = --a;
    c = a--;
    c = -a + b;
    cout << c << endl;
    c = -a - b;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
    c = a / b;
    cout << c << endl;
    x = c;
    cout << x << endl;
    system("pause");
    return 0;
}