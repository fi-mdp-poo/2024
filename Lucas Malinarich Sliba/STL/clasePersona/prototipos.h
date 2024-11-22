#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "clasePersona.h"
#include <iostream>
#include <vector>
#include <algorithm> // para std::find

void confirmarSalida(int&);
void agregarValor(std::vector<Persona>& arreglo, Persona valor);
void quitarValor(std::vector<Persona>& arreglo, Persona valor);
void imprimirVector(const std::vector<Persona>& arreglo);
void imprimirVectorInvertido(const std::vector<Persona>& arreglo);
std::vector<Persona> buscarPorApellido(const std::vector<Persona>arreglo, std::string Apellido);

#endif // PROTOTIPOS_H_INCLUDED
