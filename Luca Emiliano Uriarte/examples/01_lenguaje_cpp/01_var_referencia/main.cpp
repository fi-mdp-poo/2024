#include <iostream>
#include <string.h>

using namespace std;

struct datos                      // probar cambiar struct por class
{                                 // especificar que los atributos son publicos
    char nombre[20];
    int numero;
};

void permutar(int &, int &);       // los argumentos son referencias
int &maxref(int &, int &);         // lor argumentos y el retorno son referencias
void modif_estruc(datos &);        // referencia a la estructura datos

int main(void)
{
    int i = 10,
        j = 2;
    float fvalor = 3.14,
          &fnuevo = fvalor;
    datos alumno;

    alumno.numero = 7865;
    strcpy(alumno.nombre, "Pablo Marmol");
    cout << "El numero de " << alumno.nombre << " es " << alumno.numero << endl;

    modif_estruc(alumno);
    cout << "\nDespues de las modificaciones el numero de " << alumno.nombre << " es " << alumno.numero << endl;

    cout << "\n\nfvalor antes de modificar fnuevo = " << fvalor << endl;
    fnuevo = 2.7182;    // al modificar fnuevo se modifica fvalor
    cout << "\nfvalor despues de modificar fnuevo = " << fvalor << endl;

    cout << "\n\nAntes de permutar: i = " << i << ", j = " << j << endl;
    permutar(i, j);     // los argumentos no llevan (*) ni (&)
    cout << "\nDespues de permutar: i = " << i << ", j = " << j << endl;

    int temp = maxref(i, j);
    cout << "\n\nEl mayor entre " << i << " y " << j << " es " << temp << endl;

    maxref(i, j) = 50;   // como retorna una referencia se puede poner a la izquierda del '='
    cout << "\nAhora los valores son: i = " << i << ", j = " << j << "\n\n\n";

    return 0;
}

void permutar(int &a, int &b)     // los argumentos son referencias
{                                 // se modifican los valores de a y b
    int temp;

    temp = a;           // no hace falta utilizar
    a = b;              // el operador indirecci�n (*)
    b = temp;
}

int &maxref(int &val1, int &val2)
{
    if(val1 >= val2)
        return val1;
    else
        return val2;
}

void modif_estruc(datos &alum)
{
    alum.numero = 1234;
    strcpy(alum.nombre, "Pedro Picapiedra");
}


