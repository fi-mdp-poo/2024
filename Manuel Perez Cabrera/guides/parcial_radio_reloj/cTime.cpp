#include "cTime.h"

cTime::cTime(int h, int m, int s)
{
    hora =h;
    minutos =m;
    segundos =s;
}

//cTime::cTime(const cTime& t)
//{
//    hora = t.hora;
//    minutos = t.minutos;
//    segundos = t.segundos;
//}
cTime::~cTime()
{
    //dtor
}


///setters and getters

void cTime::Set_hora( int h )
{
    hora = h;
}
void cTime::Set_minutos( int m )
{
    minutos = m;
}
void cTime::Set_segundos( int s )
{
    segundos = s;
}
