#include "RecibodePago.h"

RecibodePago::RecibodePago(string nombre, float monto_variable, float monto_fijo, Factura* primera, Factura* ultima)
{
    SetnombreContribuyente(nombre);
    Setmonto_fijo(monto_fijo);
    Setmonto_variable(monto_variable);
    Setmonto_total(monto_fijo+monto_variable);
    SetprimeraFacturaConsiderada(primera);
    SetultimaFacturaConsiderada(ultima);
}

RecibodePago::~RecibodePago()
{
    //dtor
}
