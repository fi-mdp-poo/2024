#ifndef CPINTURA_H
#define CPINTURA_H
#include "cServicio.h"

class cPintura : public cServicio
{
public:
    ///constructores
    cPintura(string,int,int,int,int  ,int,int,int,string,int,float,float);
    virtual ~cPintura();
    ///Getters and Setters
    float GetSuperficie()
    {
        return Superficie;
    }
    void SetSuperficie(float val)
    {
        Superficie = val;
    }
    float GetPrecioPintura()
    {
        return PrecioPintura;
    }
    void SetPrecioPintura(float val)
    {
        PrecioPintura = val;
    }

    ///funciones virtuales de la clase Cservicio
    void vImprimir(ostream& os=cout) override;
    float costoMaterial() override;
    float costoManoObra()override;
    float costoTotal()override;
    void detalleServicio()override;


protected:
    float Superficie;
    float PrecioPintura;


private:
};

#endif // CPINTURA_H
