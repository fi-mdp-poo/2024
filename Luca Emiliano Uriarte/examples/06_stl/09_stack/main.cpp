#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main ()
{
    stack<int> entero;                  // vacio
    cout << "STACK DE ENTEROS\n\nTamano inicial: " << entero.size() << '\n';
    entero.push(5);                     // agrego elementos
    entero.push(-1);
    cout << "\nSe agregan 2 valores, tamano: " << entero.size() << '\n';
    int valor = entero.top();           // obtengo el valor del tope
    cout << "\tUltimo valor ingresado: " << valor << '\n';
    entero.pop();                       // elimino ese valor
    cout << "\nSe elimina un valor, tamano: " << entero.size() << '\n';
    valor = entero.top();               // nuevo valor del tope
    cout << "\tValor en el tope: " << valor << "\n\n";

    vector<float> myvector (2, 5.5);    // vector con 2 elementos = 5.5
    myvector[1] = myvector[1] + 7.5;    // segundo valor = 5.5 + 7.5
    stack<float, vector<float> > stvect(myvector);    // stack de vector inicializado
    cout << "\nSTACK DE VECTOR\n\nTamano inicial: " << stvect.size() << '\n';
    float fvalor = stvect.top();
    cout << "\tValor en el tope: " << fvalor << '\n';
    stvect.pop();
    fvalor = stvect.top();
    cout << "Se elimina un valor\n\tValor en el tope: " << fvalor << '\n';

    deque<char> mydeque;                // cola doble vacia
    mydeque.push_back('A');
    mydeque.push_front('H');
    mydeque.push_back('M');
    mydeque.push_front('Z');            // Z H A M
    stack<char> stdeq(mydeque);         // stack inicializado con una copia de deque
    cout << "\n\nSTACK DE DEQUE\n\nTamano inicial: " << stdeq.size() << '\n';
    stdeq.push('W');
    stdeq.push('r');
    cout << "\nSe agregan 2 valores, tamano: " << stdeq.size() << "\n\nValores:\n";
    char c;
    int tam = stdeq.size();
    for(int loop=0; loop<tam; loop++)
    {
        c = stdeq.top();
        stdeq.pop();
        cout << "\ttope = " << c << endl;
    };
    cout << endl << endl;

    return 0;
}
