#include <iostream>

using namespace std;

void Xhandler(int test)
{
    try
    {
        if(test==0)
            throw 5;                // throw un int
        if(test==1)
            throw 'A';              // throw un char
        if(test==2)
            throw 123.45;           // throw un double
    }
    catch(int i)                    // catch un int
    {
        cout << "Capturado un entero: " << i << "\n\n";
    }
    catch(char c)                   // catch un char
    {
        cout << "Capturado un caracter: " << c << "\n\n";
    }
    catch(double d)                 // catch un double
    {
        cout << "Capturado un double: " << d << "\n\n";
    }

    // comentando los catch se llega al general
    catch(...)                      // catch todos los tipos
    {
        cout << "Captura todos los tipos\n\n";
    }
}

int main()
{
    cout << "Inicio\n\n";
    Xhandler(0);
    Xhandler(1);
    Xhandler(2);
    cout << "\nFin\n\n";

    return 0;
}
