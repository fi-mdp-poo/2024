#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

using namespace std;

class Empleado
{
    public:
        Empleado(string n, int horas, int hijos, bool casado);
        virtual ~Empleado();

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        int GethorasTrabajadas() const { return horasTrabajadas; }
        void SethorasTrabajadas(int val) { horasTrabajadas = val; }
        int Gethijos() const { return hijos; }
        void Sethijos(int val) { hijos = val; }
        bool Getcasado() const { return casado; }
        void Setcasado(bool val) { casado = val; }

        virtual float calcularSalario() const=0;
        float calcularSalarioFamiliar() const;

    protected:

    private:
        string nombre;
        int horasTrabajadas;
        int hijos;
        bool casado;
};

#endif // EMPLEADO_H
