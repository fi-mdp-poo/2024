#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    char Nombre[50];
    cout << "Introduzca su Nombre (50 caracteres max.): ";  // ojo con los espacios
    cin.getline(Nombre, 50);

    char *CopiaNombre = new char[strlen(Nombre) + 1];  // reserva memoria para el nombre ingresado + '\0'
    // Se copia el Nombre en la variable CopiaNombre
    strcpy(CopiaNombre, Nombre);
    cout << "\n\nNombre[50] = " << Nombre << endl;
    cout << "CopiaNombre (new) = " << CopiaNombre << endl;
   // hay que hacer (void*) porque sino cout lo toma como el contenido de un string
    cout << "\n\nCopiaNombre apunta a  " << hex << (void*)CopiaNombre << "\n\n";

    delete [] CopiaNombre;       // libera memoria y destruye los datos

    int nfil = 4,                // cantidad de filas
        ncol = 3,                // cantidad de columnas
        i, j;                    // auxiliares para for()
    int **mat;                   // matriz

    // se reserva memoria para el vector de punteros
    mat = new int*[nfil];      // ver la posicion de memoria que asigna (reutiliza la anterior)
    cout << "mat esta en  " << hex << &mat << " y apunta a " << hex << mat << " (misma posicion!!)\n\n";

    // se reserva memoria para cada fila
    for (i = 0; i < nfil; i++)
    {
        mat[i] = new int[ncol];  // ver la posicion de memoria que asigna
        cout << "mat ["<< i << "] esta en  " << hex << &mat[i] << " y apunta a " << hex << mat[i] << "\n";
    }

    // se inicializa e imprime toda la matriz
    cout << "\n\nMatriz de 4x3\n";
    for(i = 0; i < nfil; i++)
    {
        for(j = 0; j < ncol; j++)
        {
            mat[i][j] = i + j;  // verificar como se va escribiendo en la memoria
            cout << "\t" << mat[i][j];
        }
        cout << "\n";
    }

    // se libera memoria: primero las filas y después el vector de punteros
    for(i = 0; i < nfil; i++)
    {
        delete [] mat[i];      // verificar en memoria como se destruyen los valores
    }
    delete [] mat;

    return 0;
}
