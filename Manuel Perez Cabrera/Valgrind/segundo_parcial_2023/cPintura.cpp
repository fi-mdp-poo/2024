#include "cPintura.h"

cPintura::cPintura(string name_trabajador,int d,int m ,int a ,int id  ,int d1,int m1,int a1 ,string name_cliente,int id_cliente,float valor_sup,float valor_material)
   :cServicio(name_trabajador,d,m,a,id,d1,m1,a1,name_cliente,id_cliente)
{

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
    cTrabajador aa = GetTrabajador();

    os<<"Trabajo de pintura:" <<endl;
    os<< aa <<endl;

    cFecha f = Getinicio_servicio();
    os<< "      Fecha de inicio:" << f<<endl;

    cCliente c = Getcliente();
    os<< c;
    os<<"       Superficie:" << GetSuperficie()<<endl;
    os<<"       Precio Pintura:" <<GetPrecioPintura()<<endl;


}
