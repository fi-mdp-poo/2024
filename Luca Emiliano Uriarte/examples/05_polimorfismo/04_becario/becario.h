#ifndef BECARIO_H
#define BECARIO_H

#include "empleado.h"
#include "estudiante.h"

class becario : public empleado, public estudiante
{
    public:
        becario();
        becario(string, unsigned, fecha,
                string, fecha, int, float,
                string, fecha, float,
                string, int, string, string);
        ~becario();
        void SetName(string);
        bool SetDocument(unsigned);     // retorna TRUE si el formato es correcto
        bool SetBirthDate(fecha);       // chequea la validez de la fecha
        bool SetBirthDate(int, int, int);       // chequea la validez de la fecha
        string stGetTipo();
        void vSetTipo(string);
        int iGetDuracion();
        void vSetDuracion(int);
        string stGetLaboratorio();
        void vSetLaboratorio(string);
        string stGetDirector();
        void vSetDirector(string);
        friend ostream& operator << (ostream&, becario&);
        void vPrint(ostream&);
      //  string GetName();
    protected:
    private:
        string stTipo;
        int iDuracion;
        string stLaboratorio;
        string stDirector;
};



#endif // BECARIO_H
