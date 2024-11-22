#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <deque>
#include <algorithm> // para std::find

void confirmarSalida(int&);
void agregarValor(std::deque<int>& fila, int valor);
void quitarValor(std::deque<int>& fila,int valor);
void imprimirFila(const std::deque<int>& fila);
void imprimirFilaInvertida(const std::deque<int>& fila);

#endif // PROTOTIPOS_H_INCLUDED
