#ifndef CFECHA_H
#define CFECHA_H


class cFecha
{
public:
    ///constructores
    cFecha();
    virtual ~cFecha();

    ///getters and getters
    int Getdia()
    {
        return dia;
    }
    void Setdia(int val)
    {
        dia = val;
    }
    int Getmes()
    {
        return mes;
    }
    void Setmes(int val)
    {
        mes = val;
    }
    int Getano()
    {
        return anio;
    }
    void Setano(int val)
    {
        anio = val;
    }

protected:
    int dia;
    int mes;
    int anio;

private:
};

#endif // CFECHA_H
