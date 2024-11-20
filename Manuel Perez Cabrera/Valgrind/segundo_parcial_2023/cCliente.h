#ifndef CCLIENTE_H
#define CCLIENTE_H
#include "string"

using namespace std;

class cCliente
{
public:
    ///constructores y destructores
    cCliente();
    virtual ~cCliente();
    ///getters and setters
    string Getnombre_cliente()
    {
        return nombre_cliente;
    }
    void Setnombre_cliente(string val)
    {
        nombre_cliente = val;
    }
    int Getcuit()
    {
        return cuit;
    }
    void Setcuit(int val)
    {
        cuit = val;
    }

protected:
    string nombre_cliente;
    int cuit;

private:
};

#endif // CCLIENTE_H
