#ifndef CIRCULO_H
#define CIRCULO_H


class circulo
{
    public:
        circulo();
        circulo(float radio);
        virtual ~circulo();

        float Getradio() { return radio; }
        void Setradio(float val) { radio = val; }
        float area();

    protected:

    private:
        float radio;
};

#endif // CIRCULO_H
