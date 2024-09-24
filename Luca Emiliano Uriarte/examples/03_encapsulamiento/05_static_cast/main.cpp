#include <iostream>
#include "tipos.h"

int main()
{
    Tiempo Ahora(12,24);
    int minutos;

    Ahora.Mostrar();
    //minutos = Ahora;              // conversion implicita
    minutos = static_cast<int> (Ahora); // enfatiza la conversion
    //minutos = int(Ahora);         // compatible con C++
    //minutos = (int)Ahora;         // compatible con C

    cout << minutos << endl << endl << endl;

    double d = 12.24;
    int i = 7;
    unsigned int u = 3;

    print(d);
    print(i);
    print(i, "segunda forma");
    print(static_cast<double>(u));      // sin el cast el compilador no sabe a qué función llamar
    //print(u);                         // se produce un error

    return 0;
}
