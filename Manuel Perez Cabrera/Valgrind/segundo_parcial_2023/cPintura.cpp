#include "cPintura.h"

cPintura::cPintura(string name_trabajador,int d,int m ,int a ,int id  ,int d1,int m1,int a1 ,string name_cliente,int id_cliente,float valor_sup,float valor_material)
   :cServicio(name_trabajador,d,m,a,id,d1,m1,a1,name_cliente,id_cliente)
{
//    trabajador.Setnombre(name_trabajador);
//    trabajador.Setfecha_ingreso(d,m,a);
//    trabajador.Setcodigo(id);
//
//    inicio_servicio.Setdia(d1);
//    inicio_servicio.Setmes(m1);
//    inicio_servicio.Setano(a1);
//
//    cliente.Setnombre_cliente(name_cliente);
//    cliente.Setcuit(id_cliente);

    SetSuperficie(valor_sup);
    SetPrecioPintura(valor_material);

}

cPintura::~cPintura()
{
    //dtor
}

float cPintura::costoMaterial()
{

}
float cPintura::costoManoObra()
{

}
float cPintura::costoTotal()
{

}
void cPintura::detalleServicio()
{

}

void cPintura::vImprimir(ostream& os)
{
    os<< "Trabajo de pintura"<<endl;
    os<< "Trabajador: " << GetTrabajador().Getnombre()<<endl;
}
