#ifndef CTRABAJADOR_H
#define CTRABAJADOR_H
#include "cFecha.h"
#include <string>


using namespace std;

class cTrabajador
{
public:
    cTrabajador(string nombre = "Defoult");
    virtual ~cTrabajador();

    string Getnombre()
    {
        return nombre;
    }
    void Setnombre(string val)
    {
        nombre = val;
    }
    cFecha Getfecha_ingreso()
    {
        return fecha_ingreso;
    }
    void Setfecha_ingreso(int d,int m,int a)
    {
        fecha_ingreso.Setdia(d);
        fecha_ingreso.Setmes(m);
        fecha_ingreso.Setano(a);
    }
    int Getcodigo()
    {
        return codigo_identificacion;
    }
    void Setcodigo(int val)
    {
        codigo_identificacion = val;
    }

    friend ostream& operator<< (ostream&, cTrabajador&);

protected:
    string nombre;
    cFecha fecha_ingreso;
    int codigo_identificacion;



private:
};

#endif // CTRABAJADOR_H
