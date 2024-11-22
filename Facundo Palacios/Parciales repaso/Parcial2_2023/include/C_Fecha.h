#ifndef C_FECHA_H
#define C_FECHA_H

#include <iostream>

using namespace std;

class C_Fecha
{
    public:
        ///Constructores y Destructores
        C_Fecha();
        virtual ~C_Fecha();

        ///Getters y Setters
        int Getdia() { return dia; }
        void Setdia(int val) { dia = val; }
        int Getmes() { return mes; }
        void Setmes(int val) { mes = val; }
        int Getano() { return ano; }
        void Setano(int val) { ano = val; }

        bool fechaEsMayor(const C_Fecha& otraFecha) const {
        if (ano != otraFecha.ano) {
            return ano > otraFecha.ano; // Comparar año
        }
        if (mes != otraFecha.mes) {
            return mes > otraFecha.mes; // Comparar mes
        }
        return dia > otraFecha.dia; // Comparar día
    }

        ///Sobrecarga
        friend ostream& operator <<(ostream& os, C_Fecha& actual);

    protected:

    private:
        int dia;
        int mes;
        int ano;
};

#endif // C_FECHA_H
