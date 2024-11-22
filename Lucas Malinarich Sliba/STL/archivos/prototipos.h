#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void confirmarSalida(int &option);
bool findFile(const string& path);
void createFile(fstream &file);
void deleteFile(const string &path);
void openFile(fstream &file, const string& path);
void writeFile(fstream &file); //REQUIERE DE UN ARCHIVO ABIERTO
void addToFile(fstream &file); //REQUIERE DE UN ARCHIVO ABIERTO

#endif // PROTOTIPOS_H_INCLUDED
