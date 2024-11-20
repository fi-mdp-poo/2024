#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class persona
{
    public:
        char nombre[10];
        int edad;

    public:

    friend ostream& operator<< (ostream& co, const persona &cmp);

};


ostream& operator<< (ostream& co, const persona &cmp)
{
    co << "nombre: " << cmp.nombre << endl;
    co << "edad: " << cmp.edad << endl;

    return co;
}

int main()
{
    persona empleado1, empleado2,empleado3;


    strcpy(empleado1.nombre, "Manuel");
    strcpy(empleado3.nombre, "juan");
    empleado1.edad = 22;
    empleado3.edad = 23;

/*
    ///Carga en un archivo bin xd.
    ofstream archivoBin;
    archivoBin.open("Archivo.bin");
    archivoBin << empleado1.nombre << empleado1.edad;
    archivoBin.close();
*/
    ///Carga una estructura en un archivo bin xd.
    ofstream archivoBin;
    archivoBin.open("Archivo.bin", ios::binary);
    archivoBin.write(reinterpret_cast<char*>(&empleado1),sizeof(persona));
    archivoBin.close();

    ///Leer una estructura de un archivo bin.

    ifstream archivoBin2;
    archivoBin2.open("Archivo.bin", ios::binary);
    archivoBin2.read(reinterpret_cast<char*>(&empleado2),sizeof(persona));
    archivoBin2.close();

    cout << empleado2;

    ofstream archivotxt;
    archivotxt.open("algo.txt");
    archivotxt << empleado2;
    archivotxt << empleado3;
    archivotxt.close();



    archivotxt.open("algo.txt",std::ios::app);
    //archivotxt.open("algo.txt");
    //fseek(archivotxt,0,SEEK_END);
    cout<< archivotxt.tellp()<<endl;
    archivotxt << empleado3;
    archivotxt << empleado3;
    archivotxt.close();
    return 0;
}
