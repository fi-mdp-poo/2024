#include "cReloj.h"


cReloj::cReloj(int h, int m, int s, string marc)
{
    Sethora(h,m,s);
    Setmarca(marc);
}

cReloj::~cReloj()
{
    //dtor
}

void cReloj::Sethora(int h, int m, int s)
{
    hora.Set_hora(h);
    hora.Set_minutos(m);
    hora.Set_segundos(s);
}
