#include "C_RevisionAlarma.h"

C_RevisionAlarma::C_RevisionAlarma(int d_s, int m_s, int a_s, string nombre_c, int cuit, int alarmas) :
    C_Servicio("Revisor Especialista Contraincendios", 02, 05, 2013, 1001, d_s, m_s, a_s, nombre_c, cuit)
{
    SetNumeroAlarmas(alarmas);
}

C_RevisionAlarma::~C_RevisionAlarma()
{
    //dtor
}

float C_RevisionAlarma::costoMaterial()
{
    return 500;
}

float C_RevisionAlarma::costoManoObra()
{
    float costo_mano_obra=(GetNumeroAlarmas()/3.0)*40;
    return costo_mano_obra;
}

float C_RevisionAlarma::costoTotal()
{
    float mano=costoManoObra();
    float material=costoMaterial();
    float total=mano+material;
    return total;
}

void C_RevisionAlarma::detalleServicio()
{

}

void C_RevisionAlarma::vImprimir(ostream& os)
{
    C_Fecha f=Getinicio_servicio();
    C_Cliente c=Getcliente();
    os<< "Trabajado de Revision de Alarma:"<<endl;
    os<<"Fecha de inicio:"<<f<<endl;
    os<<c<<endl;
    os<<"Cantidad de Alarmas:"<<GetNumeroAlarmas()<<endl;
    os<<endl;
}
