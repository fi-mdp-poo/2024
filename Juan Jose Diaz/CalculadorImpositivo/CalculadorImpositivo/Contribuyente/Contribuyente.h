#ifndef CONTRIBUYENTE_H
#define CONTRIBUYENTE_H

#include <ostream>
using namespace std;

// Clase abstracta Contribuyente
class Contribuyente {
    protected:
        string _nombre;

    public:
        explicit Contribuyente(const string& nombre);

        virtual double calcularMontoVariable(double monto) const = 0; // Método abstracto

        virtual ~Contribuyente() = default;

        string getNombre() const;
};

class Limitado final : public Contribuyente {
    public:
        /**
         * `explicit` en este caso al ser Limitado, un constructor con un solo parametro, la idea es evitar que se pueda
         * realizar una instancia implicita y forzar que sea explícita:
         * Limitado obj = "Sergio"; // Conversión Implicita. Tira una excepción con `explicit`
         * en lugar de eso, solo permitir
         * Limitado obj("Sergio"); // Construcción explícita. PERMITIDO
         */
        explicit Limitado(const string& nombre);

        /**
         * Importante, tanto los modificadores `virtual` como `override` solo se usan en la declaración del método
         * del archivo .h, con el fin de indicar que método sobreescribe a función de la clase base.
         */
        double calcularMontoVariable(double monto) const override;
};

class Completo : public Contribuyente {
    public:
        explicit Completo(const string& nombre);

        double calcularMontoVariable(double monto) const override;
};

class Extendido final : public Completo {
    public:
        explicit Extendido(const string& nombre);

        double calcularMontoVariable(double monto) const override;
};

#endif //CONTRIBUYENTE_H
