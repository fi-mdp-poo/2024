#ifndef MIEXCEPCION_H_INCLUDED
#define MIEXCEPCION_H_INCLUDED

// Excepción personalizada
class MiExcepcion{
    public:
        MiExcepcion(){}
        virtual const char* what()const throw()=0;
};

// Excepción derivada para división por cero
class DivisionPorCero : public MiExcepcion {
    public:
        DivisionPorCero(const int& num, const int& den): numerador(num), denominador(den){}
        virtual const char* what()const throw(){return "División por cero no permitida.";}

        int getNumerador() const {return numerador;}
        int getDenominador() const {return denominador;}

    private:
        int numerador;
        int denominador;
};

#endif // MIEXCEPCION_H_INCLUDED
