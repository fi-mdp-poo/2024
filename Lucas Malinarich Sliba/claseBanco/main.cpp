#include "claseCuenta.h"

int main(){
    Cuenta nuevaCuenta=Cuenta("Manuel", 2000);
    cout<<nuevaCuenta;
    nuevaCuenta.depositar(65.25);
    cout<<nuevaCuenta;
    nuevaCuenta.extraer(89.75);
    cout<<nuevaCuenta;
    return 0;
}
