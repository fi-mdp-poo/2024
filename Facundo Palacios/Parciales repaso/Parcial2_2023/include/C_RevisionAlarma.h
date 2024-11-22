#ifndef C_REVISIONALARMA_H
#define C_REVISIONALARMA_H

#include "C_Servicio.h"

using namespace std;

class C_RevisionAlarma : public C_Servicio
{
public:
    ///Constructores y Destructores
    C_RevisionAlarma(int d_s, int m_s, int a_s, string nombre_c, int cuit, int alarmas);
    virtual ~C_RevisionAlarma();

    ///Getters y Setters
    int GetNumeroAlarmas() {return NumeroAlarmas;}
    void SetNumeroAlarmas(int val){NumeroAlarmas = val;}

    ///Metodos
    float costoMaterial() override;
    float costoManoObra() override;
    float costoTotal() override;
    void detalleServicio() override;
    void vImprimir(ostream& os=cout) override;

protected:

private:
    int NumeroAlarmas;
};

#endif // C_REVISIONALARMA_H
