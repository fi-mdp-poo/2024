#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"

class estudiante : virtual public persona
{
    public:
        estudiante();
        estudiante(string, unsigned, fecha, string, fecha, int, float);
        ~estudiante();
        void SetName(string);
        bool SetDocument(unsigned);     // retorna TRUE si el formato es correcto
        bool SetBirthDate(fecha);       // chequea la validez de la fecha
        bool SetBirthDate(int, int, int);       // chequea la validez de la fecha
        string stGetCarrera();
        void vSetCarrera(string);
        fecha fechaGetIngreso();
        void vSetIngreso(fecha);
        void vSetIngreso(int, int, int);
        int iGetMaterias();
        void vSetMaterias(int);
        float fGetPromedio();
        void vSetPromedio(float);
        friend ostream& operator << (ostream&, estudiante&);
        void vPrint(ostream&);
    private:
    protected:
        string stCarrera;
        fecha fechaIngreso;
        int iMaterias;
        float fPromedio;
};



#endif // ESTUDIANTE_H
