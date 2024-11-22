#include "C_Servicio.h"

C_Servicio::C_Servicio(string nombre_t, int d_i, int m_i, int a_i, int id, int d_s, int m_s, int a_s, string nombre_c, int cuit)
{
    Trabajador.Setnombre(nombre_t);
    Trabajador.Setfecha_ingreso(d_i, m_i, a_i);
    Trabajador.Setcodigo(id);

    inicio_servicio.Setdia(d_s);
    inicio_servicio.Setmes(m_s);
    inicio_servicio.Setano(a_s);

    cliente.Setnombre_cliente(nombre_c);
    cliente.Setcuit(cuit);
}

C_Servicio::~C_Servicio()
{
    //dtor
}

ostream& operator<< (ostream&, C_Servicio&)
{

}
