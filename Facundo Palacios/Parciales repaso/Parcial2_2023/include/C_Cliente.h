#ifndef C_CLIENTE_H
#define C_CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class C_Cliente
{
    public:
        ///Constructores y Destructores
        C_Cliente();
        virtual ~C_Cliente();

        ///Getters y Setters
        string Getnombre_cliente() { return nombre_cliente; }
        void Setnombre_cliente(string val) { nombre_cliente = val; }
        int Getcuit() { return cuit; }
        void Setcuit(int val) { cuit = val; }

        ///Sobrecarga
        friend ostream& operator <<(ostream& os, C_Cliente& actual);

    protected:

    private:
        string nombre_cliente;
        int cuit;
};

#endif // C_CLIENTE_H
