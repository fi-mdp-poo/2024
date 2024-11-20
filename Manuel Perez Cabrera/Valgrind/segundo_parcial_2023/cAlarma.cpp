#include "cAlarma.h"

cAlarma::cAlarma(int d,int m ,int a,string name,int id_cliente,int cant_alarmas)
    :cServicio("Revisor Especialista Contraincendios",02,05,2013,1001,d,m,a,name,id_cliente)
///    :cServicio(d,m,a,name,id_cliente)
{
//    inicio_servicio.Setdia(d);
//    inicio_servicio.Setmes(m);
//    inicio_servicio.Setano(a);

//    cliente.Setnombre_cliente(name);
//    cliente.Setcuit(id_cliente);
    NumeroAlarmas = cant_alarmas;
}

cAlarma::~cAlarma()
{
    //dtor
}

float cAlarma::costoMaterial()
{

}
float cAlarma::costoManoObra()
{

}
float cAlarma::costoTotal()
{

}
void cAlarma::detalleServicio()
{

}

void cAlarma::vImprimir(ostream& os)
{
    os<< "Trabajo de Alarma"<<endl;

}
