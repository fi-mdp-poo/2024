#include <iostream>
#include "CMatriz.h"
#include "CPantalla.h"
#include "CColor.h"

using namespace std;

int main()
{
CMatriz original;

original.cargar("colores.bin");
cout << "Matriz original:" << endl << original << endl;

CMatriz copia(original);
CMatriz suma;

suma = original;

cout << "Matriz copia:" << endl << copia <<endl;

suma +=  (copia + 5);

cout << "Matriz suma:" << endl << suma <<endl;

CPantalla pantalla(original);
cout << "Pantalla original:" << endl << pantalla << endl;

pantalla.ajustarColor(3);
cout << "Pantalla con ajuste de color:" << endl << pantalla << endl;
//
pantalla.borrarVerde();
cout << "Pantalla sin componente verde:" << endl << pantalla << endl;
//
pantalla.reforzarRojo(0.35);
cout << "Pantalla modificada (rojo reforzado):" << endl << pantalla << endl;
//
////generar la misma informacion en un archivo de salida: pantalla.txt
//
ofstream fileout;
    fileout.open("pantalla.txt");
    fileout << "Pantalla modificada:" << endl << pantalla << endl;
    fileout.close();

    //unsigned int** algo = pantalla.getPtr();

    //cout<< algo[1][1];


CColor color(pantalla.getPtr()[pantalla.Get_filas()-1][pantalla.Get_columnas()-1]);
//
cout << "El color del ultimo punto de la pantalla es: " << endl << color << endl;

return 0;
}

