#ifndef CALCULADORIMPOSITIVO_H
#define CALCULADORIMPOSITIVO_H

#include "RecibodePago.h"
#include "Factura.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CalculadorImpositivo
{
    public:
        CalculadorImpositivo(string nombre, string categoria, float montofijo=5);
        virtual ~CalculadorImpositivo();

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        string Getcategoria() { return categoria; }
        void Setcategoria(string val) { nombre = val; }
        vector <Factura*> Getfacturas() { return facturas; }
        Factura* Getfactura(vector <Factura*> facturas, int i) {return facturas[i];}
        void Setfacturas(vector <Factura*> val) { facturas = val; }
        float Getmontofijo() { return montofijo; }
        void Setmontofijo(float val) { montofijo = val; }

        virtual RecibodePago calcularimpuesto(int, int)=0;
        virtual float montovariable(int, int)=0;

    protected:

    private:
        string nombre;
        string categoria;
        vector <Factura*> facturas;
        float montofijo;
};

#endif // CALCULADORIMPOSITIVO_H
