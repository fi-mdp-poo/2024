#include "cReloj.h"

cReloj::cReloj(int h, int m, int s)
{
    time.Set_hora(h);
    time.Set_minutos(m);
    time.Set_segundos(s);
}

cReloj::cReloj(cTime t,char* nombre)
{
    time = t;
    //time.set_hora(t.get_hora());
    //time.set_minutos(t.get_minutos());
    //time.set_segundos(t.get_segundos));
    marca = nombre;
}

cReloj::~cReloj()
{
    //dtor
}


///setters and getters

void cReloj::setTiempo(int h,int m,int s)
{
    time.Set_hora(h);
    time.Set_minutos(m);
    time.Set_segundos(s);

}

void cReloj::setMarca(char* s)
{
    marca = s;
}

cTime cReloj::getTiempo()
{
    return time;
}
