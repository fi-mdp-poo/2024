#ifndef C_MANEJADORDESERVICIOS_H
#define C_MANEJADORDESERVICIOS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "C_Servicio.h"
#include "C_TrabajoPintura.h"
#include "C_RevisionAlarma.h"

using namespace std;

class C_ManejadordeServicios
{
public:
    ///Constructores y Destructores
    C_ManejadordeServicios();
    virtual ~C_ManejadordeServicios();

    ///Getters y Setters
    vector <C_Servicio*> Getservicios(){return servicios;}
    void Setservicios(vector <C_Servicio*> val){servicios = val;}

    ///Metodos
    void Cargar_Servicios(string filename);
    void cargarServicios(string);

    void ImprimirServicios(ostream& os=cout);

    // Nueva función para ordenar los servicios por fecha
    void OrdenarPorFecha();

    // Nueva función para ordenar los servicios por nombre de cliente
    void OrdenarPorNombre();
protected:

private:
    vector <C_Servicio*> servicios;
};

#endif // C_MANEJADORDESERVICIOS_H
