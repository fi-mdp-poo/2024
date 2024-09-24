#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct persona
{
    char nombre[30];
    int edad;
    float altura;
};

int main()
{
    persona Pedro,
            Pablo;

    strcpy(Pedro.nombre, "Pedro Picapiedra");
    Pedro.edad = 59;
    Pedro.altura = 1.80;

    strcpy(Pablo.nombre, "Pablo Marmol");
    Pablo.edad = 57;
    Pablo.altura = 1.60;

    ofstream fsalida("datos.dat", ios::out|ios::binary);
    fsalida.write(reinterpret_cast<char *>(&Pedro), sizeof(persona));
//    fsalida.write((char *)(&Pedro), sizeof(persona));     // forma equivalente que anda OK
    fsalida.close();

    ifstream fentrada("datos.dat", ios::in|ios::binary);
    fentrada.read(reinterpret_cast<char *>(&Pablo), sizeof(persona));
    fentrada.close();

    cout << Pablo.nombre << ", " << Pablo.edad << " anios " << Pablo.altura << " m" << endl;

    /* *** Diferencia en la longitud del archivo entre guardar como texto o binario *** */
    float vec[100];

    ofstream fsalbn("datos.bin", ios::binary);      // modo binario
    ofstream fsaltx("datos.txt");                   // ofstream --> salida

    for(int cnt=0; cnt<100; cnt++)
    {
        vec[cnt] = float(cnt/2.11);
        fsaltx << vec[cnt] << endl;
    }
    fsalbn.write((char*)vec, 100*sizeof(float));    // se almacenan TODOS los valores en una sola escritura

    fsaltx.close();
    fsalbn.close();

    return 0;
}
