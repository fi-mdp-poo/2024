#ifndef C_TRABAJOPINTURA_H
#define C_TRABAJOPINTURA_H

#include "C_Servicio.h"

using namespace std;

class C_TrabajoPintura : public C_Servicio
{
    public:
        ///Constructores y Destructores
        C_TrabajoPintura(string nombre_t, int d_i, int m_i, int a_i, int id, int d_s, int m_s, int a_s, string nombre_c, int cuit, float sup, float precio);
        virtual ~C_TrabajoPintura();

        ///Getters y Setters
        float GetSuperficie() { return Superficie; }
        void SetSuperficie(float val) { Superficie = val; }
        float GetPrecioPintura() { return PrecioPintura; }
        void SetPrecioPintura(float val) { PrecioPintura = val; }

        ///Metodos
        float costoMaterial() override;
        float costoManoObra() override;
        float costoTotal() override;
        void detalleServicio() override;
        void vImprimir(ostream& os=cout) override;


    protected:

    private:
        float Superficie;
        float PrecioPintura;
};

#endif // C_TRABAJOPINTURA_H
