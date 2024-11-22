#ifndef CRADIO_H
#define CRADIO_H

enum TipoBanda {AM, FM};

class cRadio
{
    public:
        cRadio();
        virtual ~cRadio();

        bool Getrad() { return rad; }
        void Setrad(bool val) { rad = val; }
        float Getfrec() { return frec; }
        void Setfrec(float val) { frec = val; }
        TipoBanda Gettipo() { return tipo; }
        void Settipo(TipoBanda val) { tipo = val; }

    protected:

    private:
        bool rad;
        float frec;
        TipoBanda tipo;
};

#endif // CRADIO_H
