#ifndef CPOLAR_H
#define CPOLAR_H
#include "complejo.h"

class Cpolar : public complejo
{
    public:
        Cpolar();
        Cpolar(float , float);
        float GetModulo();
        void SetModulo(float);
        float GetFase();
        void SetFase(float);
        float Modulo(complejo&);
        float Fase(complejo&);
        float Modulo();
        friend complejo Rectang(float,float);
        void operator=(complejo);
        virtual ~Cpolar();

        friend ostream& operator<< (ostream& co, Cpolar &cmp);

    protected:

    private:
        float modulo;
        float fase;
};

#endif // CPOLAR_H
