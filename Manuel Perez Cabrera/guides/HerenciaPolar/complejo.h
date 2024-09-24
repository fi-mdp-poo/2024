#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED
#include <iostream>

using namespace std; //no se que es.

class complejo
{
    private:
        float real;
        float imaginario;

    public:
        complejo();
        ~complejo();
        void setReal(float);
        void setImaginario(float);
        float getReal();
        float getImaginario();
        complejo getComplejo();
        void setComplejo();
        void imprimirComplejo();


        ///friend complejo operator+ (const complejo& cmp0, const complejo& cmp1);
        ///friend complejo operator- (const complejo& cmp0, const complejo& cmp1);
        ///friend complejo operator* (const complejo &cmp0, const complejo& cmp1);
        ///friend complejo operator/(const complejo &cmp0, const complejo& cmp1);
        friend ostream& operator<< (ostream& co, const complejo &cmp);

        complejo operator+ (const complejo&);
        complejo operator- (const complejo& cmp0);
        complejo operator* (const complejo &cmp0);
        complejo operator/ (const complejo &cmp0);
};

#endif // COMPLEJO_H_INCLUDED
