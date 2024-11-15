#ifndef PILA2_H_INCLUDED
#define PILA2_H_INCLUDED

#include <iostream>

using namespace std;

template <class ST=char, int cnt=10> class pila
{
    private:
        ST *st;                     // memoria reservada para el stack
        int tos;                    // indice del top-of-stack
        int tam;                    // tamaño del stack
    public:
        pila()                      // constructor
            {
                tos = 0;
                tam = cnt;
                st = new ST[tam];
            }
        ~pila()                     // destructor
            {
                delete [] st;
            }
        void push(ST obj)           // agrega un objeto al stack
            {
                if(tos == tam)
                {
                    cout << "La pila esta completa.\n";
                    return;
                }
                st[tos] = obj;
                tos++;
            }
        ST pop()                   // obtiene un objeto desde el stack
            {
                if( !tos )
                {
                    cout << "La pila esta vacia.\n\n";
                    return 0;                       // return null
                }
                tos--;
                return st[tos];
            }
        friend ostream& operator<< (ostream& co, pila<ST, cnt>& obj)
            {
                cout << endl << endl;
                for(int i=0; i<obj.tos; i++)
                   cout << "Valor [" << i << "] = " << obj.st[i] << endl;
                cout << "Tamano = " << obj.tam << " ; objetos: " << obj.tos <<"\n\n";
                return co;
            }
        ST& operator[] (int indice)  // retorna la componente del indice seleccionado
            {
                if(indice && indice<=tam)
                    return st[indice];
                else
                {
                    cout << "Indice = " << indice << " excede el maximo ("
                         << tam << "). Se retorna el ultimo valor = ";
                    return st[tam-1];
                }
            }
};

#endif // PILA2_H_INCLUDED
