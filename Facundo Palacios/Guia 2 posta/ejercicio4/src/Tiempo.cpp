#include <iostream>
#include <iomanip>
#include "Tiempo.h"

using namespace std;

Tiempo::Tiempo() : hora(0), minutos(0), segundos(0) {}

Tiempo::~Tiempo(){}

void Tiempo::ingresarDatos()
{
    cout<<"Ingrese la hora (0-23): ";
    cin>> hora;
    cout<<"Ingrese los minutos (0-59): ";
    cin>> minutos;
    cout<<"Ingrese los segundos (0-59): ";
    cin>>segundos;

    if (hora < 0 || hora > 23) hora = 0;
    if (minutos < 0 || minutos > 59) minutos = 0;
    if (segundos < 0 || segundos > 59) segundos = 0;
}

void Tiempo::muestra_fmt_estandard() const
{
    string periodo = (hora >= 12) ? "PM" : "AM";
    int horaEst = (hora % 12 == 0) ? 12 : hora % 12;
    cout << setw(2) << setfill('0') << horaEst<< ":"
         << setw(2) << setfill('0') << minutos << ":"
         << setw(2) << setfill('0') << segundos << " "
         << periodo << endl;

}

void Tiempo::muestra_fmt_universal() const
{
    cout << setw(2) << setfill('0') << hora << ":"
         << setw(2) << setfill('0') << minutos << ":"
         << setw(2) << setfill('0') << segundos << endl;
}
