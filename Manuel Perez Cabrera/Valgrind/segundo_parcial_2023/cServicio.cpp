#include "cServicio.h"

cServicio::cServicio(string name_trabajador,int d,int m,int a,int id,int d1,int m1,int a1,string name_cliente,int id_cliente)
{
    trabajador.Setnombre(name_trabajador);
    trabajador.Setfecha_ingreso(d,m,a);
    trabajador.Setcodigo(id);

    inicio_servicio.Setdia(d1);
    inicio_servicio.Setmes(m1);
    inicio_servicio.Setano(a1);

    cliente.Setnombre_cliente(name_cliente);
    cliente.Setcuit(id_cliente);
}

cServicio::~cServicio()
{
    //dtor
}


ostream& operator<< (ostream&, cServicio&)
{

}
