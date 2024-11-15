#include "pila3.h"

template <class ST, int t> ostream& operator<< (ostream& co, pila<ST, t>& obj)
{
    cout << endl << endl;
    for(int i=0; i<obj.tos; i++)
    {
       cout << "Valor [" << i << "] = " << obj.st[i] << endl;
    }
    cout << "Tamano = " << obj.tam << "\n\n";

    return co;
}

int main()
{
    char car;
    pila<char, 5> st1;
    st1.push('a');
    st1.push('b');
    cout << st1;
    st1.push('c');
    cout << st1;
    car = st1.pop();
    cout << "Caracter sacado del stack = " << car << endl;
    cout << st1;

    pila<double, 10> ds1;
    ds1.push(1.1);
    ds1.push(3.3);
    ds1.push(5.5);
    cout << ds1;

/***   se produce error porque en pila3.cpp no se declaró template class pila <string, 10>;   ***/
/*    string texto;
    pila<string, cnt> pstr;
    pstr.push("hola");
*/
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
