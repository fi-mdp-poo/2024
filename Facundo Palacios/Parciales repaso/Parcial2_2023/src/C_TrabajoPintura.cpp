#include "C_TrabajoPintura.h"

C_TrabajoPintura::C_TrabajoPintura(string nombre_t, int d_i, int m_i, int a_i, int id, int d_s, int m_s, int a_s, string nombre_c, int cuit, float sup, float precio):
    C_Servicio(nombre_t, d_i, m_i, a_i, id, d_s, m_s, a_s, nombre_c, cuit)
{

    SetSuperficie(sup);
    SetPrecioPintura(precio);
}

C_TrabajoPintura::~C_TrabajoPintura()
{
    //dtor
}

float C_TrabajoPintura::costoMaterial()
{
    float material=(GetSuperficie()/7.8)*GetPrecioPintura();
    return material;
}
float C_TrabajoPintura::costoManoObra()
{
    float mano=(GetSuperficie()/10)*9.5;
    return mano;
}
float C_TrabajoPintura::costoTotal()
{
    float mano=costoManoObra();
    float material=costoMaterial();
    float total=mano+material;
    float sup=GetSuperficie();
    if(sup<50.0)
    {
        total+=total*0.15;
    }
    return total;
}

void C_TrabajoPintura::detalleServicio()
{

}

void C_TrabajoPintura::vImprimir(ostream& os)
{
    C_Trabajador t=GetTrabajador();
    C_Fecha f=Getinicio_servicio();
    C_Cliente c=Getcliente();
    os<< "Trabajo de pintura:"<<endl;
    os<< t <<endl;
    os<<"Fecha de inicio:"<<f<<endl;
    os<<c<<endl;
    os<<"Superficie:"<<GetSuperficie()<<endl;
    os<<"Precio pintura:"<<GetPrecioPintura()<<endl;
    os<<endl;
}
