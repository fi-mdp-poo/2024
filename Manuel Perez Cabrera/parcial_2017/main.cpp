#include <iostream>
#include <map>
#include "CTransporte.h"
#include "persona.h"
#include "CMaritimo.h"
#include "CTerrestre.h"
#include <fstream>

using namespace std;

template <class K, class V> void vPrintMap(map<K, V> &mapa, ostream& co)
{

    for (typename map<K, V>::iterator it = mapa.begin(); it != mapa.end(); ++it)
    {
        co << *(it->second) << endl;
    }

}

template <class K, class V> void vPrintMap(map<K, V> &mapa, string nombre)
{

    // Abrir el archivo en modo escritura
    ofstream archivo(nombre, ios::out);

    // Manejo de errores al abrir el archivo
    if (!archivo.is_open())
    {
        cerr << "Error: No se pudo crear o abrir el archivo " << nombre << endl;
        return;
    }

    // Escribir el contenido del mapa en el archivo
    try
    {

        for (typename map<K, V>::iterator it = mapa.begin(); it != mapa.end(); ++it)
        {
            archivo << *(it->second) << endl;
        }

    }
    catch (const exception &e)
    {
        cerr << "Error al escribir en el archivo: " << e.what() << endl;
        archivo.close();
        return;
    }

    archivo.close();

}


int main()
{

    map<string, CTransporte *> mapMoviles;
    map<int, persona *> mapPersonas;
    CMaritimo *CMBarco = new CMaritimo();
    CMaritimo *CMVelero = new CMaritimo("CZX023", "Esperanza", 0x7000FF, 5);
    CTerrestre *CTAuto = new CTerrestre();
    mapMoviles.insert(pair<string, CTransporte*>(CMVelero->GetMatricula(), CMVelero));
    /* declarando las clases derivadas se pueden usar los getters y setters */
    CMBarco->SetPasajeros(500);
    CMBarco->SetMatricula("AUB734");
    CMBarco->SetNombre("Titanic");
    CTAuto->SetMatricula("AA769DB");
    CTAuto->SetVelocidad(197.8);
    CTAuto->SetColor(0x050FF0FF);
    CMBarco->SetColor(CTAuto->GetColor().GetColor());
    mapMoviles.insert(pair<string, CTransporte*>(CMBarco->GetMatricula(), CMBarco));
    mapMoviles.insert(pair<string, CTransporte*>(CTAuto->GetMatricula(), CTAuto));
    CTerrestre *CTMoto = new CTerrestre();
    CTMoto->SetMatricula("007XYZ");
    CTMoto->SetVelocidad(87.5);
    CTMoto->GetColor().SetRed(225);
    CTMoto->GetColor().SetGreen(0);
    CTMoto->GetColor().SetBlue(105);
    CTMoto->SetRuedas(2);
    CTMoto->SetMarca("Honda");
    mapMoviles.insert(pair<string, CTransporte*>(CTMoto->GetMatricula(), CTMoto));
    vPrintMap(mapMoviles, cout);
    vPrintMap(mapMoviles, "prueba_moviles.txt");
    persona *Roberto = new persona("Roberto", 12516857, CFecha(26, 10)),
    *Pedro = new persona(),
    *Pablo = new persona("Pablo", 92736675, CFecha(25, 10, 1980));
    mapPersonas.insert(pair<int, persona*>(Roberto->GetDocument(), Roberto));
    mapPersonas.insert(pair<int, persona*>(Pedro->GetDocument(), Pedro));
    mapPersonas.insert(pair<int, persona*>(Pablo->GetDocument(), Pablo));
    vPrintMap(mapPersonas, cout);
    vPrintMap(mapPersonas, "prueba_personas.txt");
    return 0;
}
