// fichero complejos.cpp
// funciones y operadores de la clase complejo

#include "complejos.h"
/*
// constructor por defecto
complejo::complejo(void)
{
    SetReal(0.0);
    SetImag(0.0);
}
*/
// constructor general
complejo::complejo(double real, double imag)
{
    m_real = real;
    m_imag = imag;
}
/*
// constructor de copia
complejo::complejo(const complejo &c)
{
    m_real = c.m_real;
    m_imag = c.m_imag;
}
*/
// funciones Sets()
void complejo::SetData(void)
{
    cout << "Introduzca el valor real del complejo: ";
    cin >> m_real;
    cout << "Introduzca el valor imaginario del complejo: ";
    cin >> m_imag;
}

void complejo::SetReal(double real)
{
    m_real = real;
};

void complejo::SetImag(double imag)
{
    m_imag = imag;
};

// Gets()
double complejo::GetReal(void)
{
    return m_real;
};

double complejo::GetImag(void)
{
    return m_imag;
};

// operadores miembro sobrecargados
/***
complejo& complejo::operator+ (const complejo &cmp)
{
    complejo *suma = new complejo;
  */  /*complejo suma;
    suma.m_real = m_real + cmp.m_real;
    suma.m_imag = m_imag + cmp.m_imag;

    return suma;*/
 /***   suma->m_real = m_real + cmp.m_real;
    suma->m_imag = m_imag + cmp.m_imag;

    return *suma;
}
***/
complejo complejo::operator+ (const complejo &cmp)
{
    complejo suma;

    suma.m_real = m_real + cmp.m_real;
    suma.m_imag = m_imag + cmp.m_imag;

    return suma;
}

complejo complejo::operator- (const complejo &cmp)
{
    complejo resta;
    resta.m_real = m_real - cmp.m_real;
    resta.m_imag = m_imag - cmp.m_imag;

    return resta;
}

complejo complejo::operator* (const complejo &cmp)
{
    complejo producto;
    producto.m_real = m_real*cmp.m_real - m_imag*cmp.m_imag;
    producto.m_imag = m_real*cmp.m_imag + m_imag*cmp.m_real;

    return producto;
}

complejo complejo::operator/ (const complejo &cmp)
{
    complejo cociente;
    double deno;

    deno = cmp.m_real*cmp.m_real + cmp.m_imag*cmp.m_imag;
    cociente.m_real = (m_real*cmp.m_real + m_imag*cmp.m_imag)/deno;
    cociente.m_imag = (-m_real*cmp.m_imag + m_imag*cmp.m_real)/deno;

    return cociente;
}

complejo complejo::operator= (const complejo &cmp)
{
    m_real = cmp.m_real;
    m_imag = cmp.m_imag;

    return (*this);
}

complejo complejo::operator+= (const complejo &cmp)
{
    m_real+= cmp.m_real;
    m_imag+= cmp.m_imag;

    return (*this);
}

complejo& complejo::operator++()                   // pre-incremento
{
    m_real++;
    m_imag++;

    return (*this);
}
/*************
complejo& complejo::operator++(int dummy)          // post-incremento
{
    complejo *aux = new complejo;

    *aux = *this;
    //aux->m_real = m_real;
    //aux->m_imag = m_imag;

    ++(*this);
    //m_real++;
    //m_imag++;

    return (*aux);
}
****************/

complejo& complejo::operator++(int dummy)          // post-incremento
{
    complejo &aux = *this;

    ++(*this);

    return (aux);
}

/************** definicion con el modificador friend
int operator== (const complejo& a, const complejo& b)
{
    if ( (a.real == b.real) && (a.imag == b.imag) )
        return 1;
    else
        return 0;
}
**************/

bool complejo::operator== (const complejo& cmp)           // sin utilizar el modificador friend
{
    if ( (m_real == cmp.m_real) && (m_imag == cmp.m_imag) )
        return 1;
    else
        return 0;
}

bool operator!= (const complejo& cmp1, const complejo& cmp2)
{
    if ( (cmp1.m_real != cmp2.m_real) || (cmp1.m_imag != cmp2.m_imag) )
        return 1;
    else
        return 0;
}

ostream& operator<< (ostream& co, const complejo &cmp)
{
    ios_base::fmtflags fl;
    //int fl;

    co << cmp.m_real;
    fl = co.setf(ios::showpos);
    co << cmp.m_imag << "i";
    co.flags(fl);

    return co;
}

complejo operator+ (double d, complejo c)
{
    complejo nuevo;

    nuevo.m_real = c.m_real + d;
    nuevo.m_imag = c.m_imag;

    return nuevo;
}

