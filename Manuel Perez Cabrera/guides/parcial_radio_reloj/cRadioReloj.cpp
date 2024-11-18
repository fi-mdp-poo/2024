#include "cRadioReloj.h"

cRadioReloj::cRadioReloj(cTime reloj,cTime alarm,TipoAlarma t ,bool alar  , float band ,TipoDeBanda tipp , bool rad )
    :cReloj(reloj),cRadio(band,tipp,rad)
{
   alarma = alarm;
   tipo = t;
   prendido = alar;
}

cRadioReloj::~cRadioReloj()
{
    //dtor
}


void cRadioReloj::setAlarma(int hora, int minutos, int segundos)
{
    alarma.Set_hora(hora);
    alarma.Set_minutos(minutos);
    alarma.Set_segundos(segundos);
}
