#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"

class empleado : virtual public persona
{
    public:
        empleado();
        empleado(string, unsigned, fecha, string, fecha, float);
        empleado(string, unsigned, int, int, int, string, int, int, int, float);
        ~empleado();
  //      void SetName(string);
        bool SetDocument(unsigned);     // retorna TRUE si el formato es correcto
        bool SetBirthDate(fecha);       // chequea la validez de la fecha
        bool SetBirthDate(int, int, int);       // chequea la validez de la fecha
        string stGetCategoria();
        void vSetCategoria(string);
        void vSetIngreso(fecha);
        void vSetIngreso(int, int, int);
        fecha fechaGetIngreso();
        float fGetSueldo();
        void vSetSueldo(float);
        friend ostream& operator << (ostream&, empleado&);
        void vPrint(ostream&);
    private:
    protected:
        string stCategoria;
        fecha fechaIngreso;
        float fSueldo;
};



#endif // EMPLEADO_H
