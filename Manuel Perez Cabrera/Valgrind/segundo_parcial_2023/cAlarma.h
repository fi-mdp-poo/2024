#ifndef CALARMA_H
#define CALARMA_H
#include <string>
#include "cServicio.h"



using namespace std;

class cAlarma : public cServicio
{
public:
    cAlarma(int,int,int,string,int,int);
    virtual ~cAlarma();
    ///getters and setters
    int GetNumeroAlarmas()
    {
        return NumeroAlarmas;
    }
    void SetNumeroAlarmas(int val)
    {
        NumeroAlarmas = val;
    }

    ///funciones virtuales de la clase Cservicio
    void vImprimir(ostream& os=cout) override;
    float costoMaterial() override;
    float costoManoObra()override;
    float costoTotal()override;
    void detalleServicio()override;

protected:
    int NumeroAlarmas;

private:
};

#endif // CALARMA_H
