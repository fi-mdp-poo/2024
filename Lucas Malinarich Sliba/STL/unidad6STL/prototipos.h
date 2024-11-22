#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <vector>
#include <algorithm> // para std::find

void confirmarSalida(int&);
void agregarValor(std::vector<int>& arreglo, int valor);
void quitarValor(std::vector<int>& arreglo,int valor);
void imprimirVector(const std::vector<int>& arreglo);
void imprimirVectorInvertido(const std::vector<int>& arreglo);

#endif // PROTOTIPOS_H_INCLUDED
