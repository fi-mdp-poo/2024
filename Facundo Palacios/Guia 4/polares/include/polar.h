#ifndef POLAR_H
#define POLAR_H
#include "../complejos.h"

class polar : public complejos
{
    public:
        polar();
        polar(float modulo, float fase);
        virtual ~polar();

        float GetfModulo() const { return fModulo; }
        void SetfModulo(float val) { fModulo = val; }
        float GetfFase() const { return fFase; }
        void SetfFase(float val) { fFase = val; }

        float Modulo(const complejos& other);
        float Fase(const complejos& other);
        float Modulo();
        friend complejos Rectang(float modulo,float fase);
        polar& operator=(const complejos& other);

    protected:

    private:
        float fModulo;
        float fFase;
};

#endif // POLAR_H
