#ifndef CONTRIBUYENTE_H
#define CONTRIBUYENTE_H

#include <string>
#include <vector>
#include "factura.h"

using namespace std;

class Contribuyente{
    protected:
        string nombre;
        vector<Factura> facturas;

    public:
        /// Constructor y Destructor ///
        Contribuyente(const string& nombre);
        virtual ~Contribuyente();

        /// Metodos ///
        void agregarFactura(const Factura& factura);
        virtual float calcularMontoVariable(const Factura& factura) const = 0;

        /// Getters ///
        string getNombre() const;
        const vector<Factura>& getFacturas() const;
};

class Limitado : public Contribuyente{
    public:
        /// Constructor y Destructor ///
        Limitado(const string& name);
        virtual ~Limitado();

        /// Metodo ///
        float calcularMontoVariable(const Factura& factura) const override;
};

class Completo : public Contribuyente {
    public:
        /// Constructor y Destructor ///
        Completo(const string& name);
        virtual ~Completo();

        /// Metodo ///
        float calcularMontoVariable(const Factura& factura) const override;
};

class Extendido : public Contribuyente {
    public:
        /// Constructor y Destructor ///
        Extendido(const string& name);
        virtual ~Extendido();

        /// Metodo ///
        float calcularMontoVariable(const Factura& factura) const override;
};

#endif
