#include "claseCuenta.h"


ostream& operator<<(ostream &Cout, const Cuenta &cuentaBanco){
    cout<<"Titular de la cuenta: "<<cuentaBanco.getTitular();
    cout<<"\nSaldo de la cuenta: $"<<cuentaBanco.getSaldo()<<endl;
    return Cout;
}

Cuenta::Cuenta(string nombre, double monto){
    setTitular(nombre);
    setSaldo(monto);
}

Cuenta::~Cuenta(){  }

void Cuenta::setTitular(string nombre){ titular=nombre; }
void Cuenta::setSaldo(double monto){ saldo=monto; }
string Cuenta::getTitular()const{ return titular; }
double Cuenta::getSaldo()const{ return saldo; }

void Cuenta::depositar(double monto){ saldo+=monto; }
void Cuenta::extraer(double monto){ saldo-=monto; }
