#include "pila h_full.h"
#include "persona.h"

int main()
{
    char car;
    pila<> st1;                 // tipo por defecto = char y tamano por defecto = 10
    st1.push('a');
    st1.push('b');
    cout << st1;
    st1.push('c');
    cout << st1;
    car = st1.pop();
    cout << "Caracter sacado del stack = " << car << endl;
    cout << st1;

    pila<double> ds1;           // tipo = double, tamaño por defecto = 10
    ds1.push(1.1);
    ds1.push(3.3);
    ds1.push(5.5);
    cout << ds1;

    string texto;
    pila<string, 5> pstr;       // tipo = string, tamano = 5
    pstr.push("hola");
    pstr.push("mundo");
    pstr.push("y chau demasiado largo");
    pstr.push("ojala! ");
    pstr.push("cosa de mandinga! ");
    cout << pstr;
    pstr.push("sin mostrar ");
    texto = pstr[6];
    cout << texto << endl;
    pstr.pop();
    texto = pstr.pop();
    cout << "Texto sacado del stack = " << texto << endl;
    cout << pstr;

    persona ped,
            pab("Pablo", 987654321, fecha(11,10,2016)),
            pau("Vilma");
    pila<persona, 2> ppers;     // tipo = persona, tamano = 2
    ppers.push(ped);
    ppers.push(pab);
    cout << ppers;
    ppers.push(pau);

    return 0;
}
