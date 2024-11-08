#include <iostream>
#include "persona.h"

using namespace std;

template <class, const int> class pila;   // declaración previa para el próximo template
template <class ST, const int cnt> ostream& operator<< (ostream&, pila<ST, cnt>&);

template <class ST=char, const int cnt=10> class pila
{
    private:
        ST *st;                     // memoria reservada para el stack
        int tos;                    // indice del top-of-stack
        int tam;                    // tamaño del stack
    public:
        pila();                     // constructor
        ~pila();                    // destructor
        void push(ST);              // agrega un objeto al stack
        ST pop();                   // obtiene un objeto desde el stack
        friend ostream& operator<< <> (ostream& co, pila<ST, cnt>&);  // signo <>!!!
        ST& operator[] (int);       // retorna la componente del indice seleccionado
};

template <class ST, const int cnt> ST& pila<ST, cnt>::operator[](int indice)
{
    if(indice<tam)
    {
        return st[indice];
    }
    else
    {
        cout << "Indice = " << indice << " excede el maximo ("
             << tam << "). Se retorna el ultimo valor = ";
        return st[tam-1];
    }
}

template <class ST, const int t> ostream& operator<< (ostream& co, pila<ST, t>& obj)  // no se incluye <>!!
{
    for(int i=0; i<obj.tos; i++)
    {
       cout << "Valor [" << i << "] = " << obj.st[i] << endl;
    }
    cout << "Tamano = " << obj.tam << "\n\n\n";

    return co;
}

template <class ST, const int cnt> pila<ST, cnt>::pila()
{
    tos = 0;
    tam = cnt;
    st = new ST[tam];
}

template <class ST, const int cnt> pila<ST, cnt>::~pila()
{
    delete [] st;
}

template <class ST, const int cnt> void pila<ST, cnt>::push(ST obj)
{
    if(tos == tam)
    {
        cout << "La pila esta completa.\n";
        return;
    }
    st[tos] = obj;
    tos++;
}

template <class ST, const int cnt> ST pila<ST, cnt>::pop()
{
    if( !tos )
    {
        cout << "La pila esta vacia.\n\n";
        return st[0];                       // return null
    }
    tos--;

    return st[tos];
}

int main()
{
    char car;
    const int cnt = 5;
    pila<char, cnt> st1;                 // tipo por defecto = char y tamano por defecto = 10
    st1.push('a');
    st1.push('b');
    cout << st1;
    st1.push('c');
    cout << st1;
    car = st1.pop();
    cout << "Caracter sacado del stack = " << car << endl;
    cout << st1;
    car = st1[1];
    cout << "Acceso al stack mediante el indice: " << car << endl;
    st1[1] = 'z';
    cout << "Modifico un caracter del stack a traves del indice\n" << st1 << endl;

    double dou;
    pila<double, 10> ds1;           // tipo = double, tamaño por defecto = 10
    ds1.push(1.1);
    ds1.push(3.3);
    ds1.push(5.5);
    cout << ds1;
    dou = ds1[1];
    cout << "Acceso al stack mediante el indice: " << dou << endl;
    ds1[2] = 111.22;
    cout << "Modifico un double del stack a traves del indice\n" << ds1 << endl;

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
    cout << "\nTexto sacado del stack = " << texto << endl;
    cout << pstr;
    texto = pstr[1];
    cout << "Acceso al stack mediante el indice:\n" << pstr << endl;
    pstr[2] = "modificado";
    cout << "Modifico un string del stack a traves del indice\n" << pstr << endl;

    persona ped,
            pab("Pablo", 987654321, fecha(11,10,2016)),
            pau("Vilma");
    pila<persona, 4> ppers;     // tipo = persona, tamano = 4
    ppers.push(ped);
    ppers.push(pab);
    ppers.push(pau);
    cout << ppers;

    ped = ppers[1];
    cout << "\nAcceso al stack mediante el indice:\n" << ped << endl;
    pau.SetName("Roberto");
    pau.SetDocument(1122334455);
    pau.SetBirthDate(29, 2, 1960);
    ppers[0] = pau;
    cout << "Modifico una persona del stack a traves del indice\n" << ppers << endl;

    return 0;
}
