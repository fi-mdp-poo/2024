#include "cTime.h"

cTime::cTime(int hora, int minuto, int segundo)
{
    Set_hora(hora);
    Set_minutos(minutos);
    Set_segundos(segundos);
}

cTime::~cTime()
{

}

void cTime::Set_hora(int val)
{
    hora=val;
}
void cTime::Set_minutos(int val)
{
    minutos=val;
}
void cTime::Set_segundos(int val)
{
    segundos=val;
}
