#include <iostream>
#include <fstream>

using namespace std;

enum acceso {IN, OUT};

void Xhandler(const char* , acceso, fstream*);
void Backup(void);

int main()
{
    // inicio del programa

    try
    {
        Backup();
    }
    catch (acceso valor)
    {
        cout << "\n\nManejo de la exepcion relanzada:\n";
        if(valor)
            cout << "\tError en el fichero de salia\n";
        else
            cout << "\tError en el fichero de origen\n";
        // rutina de manejo del error
    }

    // resto del programa sin error

    return 0;
}

void Xhandler(const char* nombre, acceso modo, fstream *fh)
{
    if (modo)                  // escritura
        fh->open(nombre, ios_base::out | ios_base::binary);
    else                        // lectura
        fh->open(nombre, ios_base::in | ios_base::binary);

    if( !fh->good() )
        throw modo;
}

void Backup(void)
{
    char Origen[] = "datos.txt";                 // no existe, cambiar por main.cpp
    char Destino[] = "excepcion.cpy";
    fstream *fin = new fstream,
            *fout = new fstream;

    try
    {
        Xhandler(Origen, IN, fin);
        Xhandler(Destino, OUT, fout);
    }
    catch (acceso valor)
    {
        if(valor)
        {
            cout << "El fichero de salida no se puede abrir\n\n";
            fin->close();
        }
        else
            cout << "El fichero de origen no existe\n\n";

        throw ;         // relanzo la excepcion para comunicar al main()
    }

    //  Algoritmo de copia

    fin->close();
    fout->close();
}
