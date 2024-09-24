#include "Cpolar.h"
#include <math.h>

Cpolar::Cpolar()
{
    float aux;

    aux = complejo::getReal()*complejo::getReal() + complejo::getImaginario()*complejo::getImaginario();
    this->modulo = sqrt(aux);

    aux = atan(complejo::getImaginario()/complejo::getReal());
    this->fase =aux;

}

Cpolar::~Cpolar()
{
    //dtor
}

Cpolar::Cpolar(float _modulo, float _fase)
{
    complejo::setReal(_modulo*cos(_fase));
    complejo::setImaginario(_modulo*sin(_fase));
    SetModulo(_modulo);
    SetFase(_fase);
}

float Cpolar::GetModulo()
{
    return modulo;
}

void Cpolar::SetModulo(float _modulo)
{
    modulo = _modulo;
}

float Cpolar::GetFase()
{
 return fase;
}

void Cpolar::SetFase(float _fase)
{
    fase= _fase;
}

float Cpolar::Modulo(complejo& c1)
{
    float aux;

    aux = c1.getReal()*c1.getReal() + c1.getImaginario()*c1.getImaginario();
    aux = sqrt(modulo);

    return aux;
}

float Fase(complejo& c1)
{
    float aux;
    aux = atan(c1.getImaginario()/c1.getReal());

    return aux;
}

float Modulo()
{

}

complejo Rectang(float a,float b)
{

}
//void operator=(complejo n)
//{
//}


ostream& operator<< (ostream& co, Cpolar &cmp)
{
    cout<<" "<<(complejo)cmp <<" estoy imprimiendo desde polar el complejo"<< endl;
    cout << "su modulo es " << cmp.GetModulo()<<endl;
    cout << "su fase es " << cmp.GetFase()<<endl;


}
