#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <list>
#include <algorithm> // para std::find

void confirmarSalida(int&);
void agregarValor(std::list<int>& lista, int valor);
void quitarValor(std::list<int>& lista,int valor);
void imprimirLista(const std::list<int>& lista);
void imprimirListaInvertida(const std::list<int>& lista);

#endif // PROTOTIPOS_H_INCLUDED
