#ifndef CRADIO_H
#define CRADIO_H


enum TipoDeBanda {AM, FM};
class cRadio
{
public:
    cRadio(float frecuencia = 95.5 , TipoDeBanda = FM , bool prendido = false);
    ~cRadio();

///setters and getters

    void setPrendido(bool);
    void setBanda(TipoDeBanda);

protected:
    float frecuencia;
    TipoDeBanda banda;
    bool prendido;

};

#endif // CRADIO_H
