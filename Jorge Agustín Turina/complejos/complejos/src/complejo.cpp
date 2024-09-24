#include "complejo.h"

complejo::complejo()
{
    real = new int(5);
    imaginario = new int(0);
}

complejo::complejo(int real1, int img)
{
    real = new int(real1);
    imaginario = new int(img);
}

void complejo::set_real(int n)
{
    *real = n;
}

void complejo :: set_imaginario(int i)
{
    *imaginario = i;
}

int complejo::get_real() const ///ESTO POR QUE LO PIDE LA CARGA DEL OP INT + COMPLEJO?
{
    return *real;
}

int complejo::get_imaginario() const
{
    return *imaginario;
}



/*
ostream& operator<< (ostream& os, complejo &com)
{

    os << showpos << com.get_real() << " ";
    os << showpos <<com.get_imaginario() << " j" <<endl;

    return os;
}*/

ostream& operator<< (ostream& os ,complejo &com)
{

    os << showpos << com.get_real() << " ";
    os << showpos <<com.get_imaginario() << " j" <<endl;

    return os;
}





complejo& complejo::operator + (complejo &a)
{

    complejo &c3 = *this;

    c3.set_real(*this->real + a.get_real());
    c3.set_imaginario( *this->imaginario + a.get_imaginario());

    return c3;
}


complejo complejo::operator * (const complejo& a) {
    complejo resultado = *this;
    resultado.set_real(a.get_real() + *this->real);
    resultado.set_imaginario(a.get_imaginario() + 20);
    return resultado;
}

///PRUEBA sobrecargar operador y devolver otro tipo de dato
/*
int complejo::operator * ( complejo& a) {
    int resultado = 0;
    complejo& invocador = *this;
    resultado = invocador.get_real() + invocador.get_imaginario() + a.get_real() + a.get_imaginario();

    return resultado;
}
*/

int operator + (int b, const complejo& a){

    return b+a.get_real();

}


/*
int complejo::operator(int)(complejo &a){
    return a.get_real();

}*/


complejo complejo::operaciones(const complejo& c1, complejo c2) const{
    complejo a;
    complejo b = c1;
    cout << "adentro de la f c1:" << b;
    b.set_imaginario(0);


    b.imaginario = new int; ///
    int *p = new int;
    *p = 4;
    b.imaginario = p; ///
    //b->imaginario = 6; ///????

    c2.set_imaginario(80);
    a.set_real(-15);
    //this->set_real(22); ESTO ES LO QUE NO ME PERMITE CONST CUAL?


    return a;

}
        complejo complejo::operaciones1(const complejo c1, complejo c2){
            complejo a;

        complejo b = c1;
        cout << "adentro de la f c1 operaciones1:" << b;
        b.set_imaginario(60);

        c2.set_imaginario(60);

        this->set_real(22);


            return a;

        }
