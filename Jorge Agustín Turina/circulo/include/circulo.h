#ifndef CIRCULO_H
#define CIRCULO_H


class circulo
{
    public:
        circulo();
        virtual ~circulo();

        int Getradio();
        int Getarea();
        void Setradio(int val);

    protected:

    private:
        int radio;
        int area;
};

#endif // CIRCULO_H
