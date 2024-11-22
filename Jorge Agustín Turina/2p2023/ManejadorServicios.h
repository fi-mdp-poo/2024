#ifndef MANEJADORSERVICIOS_H
#define MANEJADORSERVICIOS_H

using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include "TrabajoPintura.h"

class ManejadorServicios
{
    public:
        ManejadorServicios();
        virtual ~ManejadorServicios();
        void cargar_datos(string nombre_archivo = "default.bin");
        void cargar_datos2(string nombre_archivo = "default.bin");
    protected:

    private:

};

#endif // MANEJADORSERVICIOS_H
