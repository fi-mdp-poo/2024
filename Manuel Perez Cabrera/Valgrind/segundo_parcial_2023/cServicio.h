#ifndef CSERVICIO_H
#define CSERVICIO_H
#include "cTrabajador.h"
#include "cCliente.h"

#include <iostream>


using namespace std;


class cServicio
{
public:
    cServicio(string name_trabajador,int d,int m,int a,int id,int d1,int m1,int a1,string name_cliente,int id_cliente);
///    cServicio(string name_trabajador ,int d ,int m ,int a ,int id ,int d1,int m1,int a1,string name_cliente,int id_cliente);
    virtual ~cServicio();

    cTrabajador GetTrabajador()
    {
        return trabajador;
    }
    void SetTrabajador(cTrabajador val)
    {
        trabajador = val;
    }
    cFecha Getinicio_servicio()
    {
        return inicio_servicio;
    }
    void Setinicio_servicio(cFecha val)
    {
        inicio_servicio = val;
    }
    cCliente Getcliente()
    {
        return cliente;
    }
    void Setcliente(cCliente val)
    {
        cliente = val;
    }


    friend ostream& operator<< (ostream&, cServicio&); ///tiene que ir si o si o se rompe

    virtual void vImprimir(ostream& os=cout)=0;
    virtual float costoMaterial()=0;
    virtual float costoManoObra()=0;
    virtual float costoTotal()=0;
    virtual void detalleServicio()=0;

protected:
    cTrabajador trabajador;
    cFecha inicio_servicio;
    cCliente cliente;

private:
};

#endif // CSERVICIO_H
