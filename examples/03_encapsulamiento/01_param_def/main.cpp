#include <iostream>

using namespace std;

void print(int cnt,            // parámetro que no puede faltar
           char c = 'Z',       // si no se especifica se usa Z
           int i = 17,
           float f = 3.1416);

int main()
{

    cout << "Llamada a print(4): ";
    print(4);
    cout << "Llamada a print(4, 'A'): ";
    print(4, 'A');
    cout << "Llamada a print(4, 'A', -18): ";
    print(4, 'A', -18);
    cout << "Llamada a print(4, 'A', -18, 4.2568): ";
    print(4, 'A', -18, 4.2568);

    return 0;
}

void print(int cnt, char c, int i, float f)
{
    cout << "entero = " << cnt
         << "; caracter = " << c
         << "; entero = " << i
         << "; flotante = " << f << endl << endl;
}
