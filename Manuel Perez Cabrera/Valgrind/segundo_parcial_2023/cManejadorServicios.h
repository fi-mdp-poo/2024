#ifndef CMANEJADORSERVICIOS_H
#define CMANEJADORSERVICIOS_H
#include "cServicio.h"
#include "cPintura.h"
#include "cAlarma.h"
#include <vector>
#include <iostream>

#include <string>
#include <fstream>

using namespace std;

class cManejadorServicios
{
public:
    cManejadorServicios();
    virtual ~cManejadorServicios();

    void cargarServicios(string);

    void ImprimirServicios(ostream& os=cout);

protected:
    vector<cServicio*> servicios;

private:
};

#endif // CMANEJADORSERVICIOS_H
