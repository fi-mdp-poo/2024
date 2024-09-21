#include "cReloj.h"


/***
** CRELOJ
**/
cReloj::cReloj(cTime tiempo)
{
    time = tiempo;
    marca = NULL;
}

cReloj::~cReloj()
{
    if(marca != NULL)
    delete marca;
}


cReloj::cReloj(int h, int m, int s)
{
    time.set_hora(h);
    time.set_minuto(m);
    time.set_segundo(s);

    marca = NULL;
}

void cReloj::setTiempo(int h, int m, int s)
{
    time.set_hora(h);
    time.set_minuto(m);
    time.set_segundo(s);
}

void cReloj::setMarca(const char* mark)
{

    marca = new char[strlen(mark)+1];
    strcpy(marca, mark);

}

cTime cReloj::getTiempo()
{
    return time;
}


/***
** CTIME
**/
cTime::cTime(int h, int m, int s)
{
    set_hora(h);
    set_minuto(m);
    set_segundo(s);
}

void cTime::set_hora(int h)
{
    hora = h;
}
void cTime::set_minuto(int m)
{
    minuto = m;
}
void cTime::set_segundo(int s)
{
    segundo = s;
}
int cTime::get_hora()
{
    return hora;
}


ostream& operator<< (ostream& co, const cTime &cmp)
{

    co <<" hora: " << cmp.hora << " minuto: " << cmp.minuto << " segundo: " << cmp.segundo;

    return co;
}



/***
** CRADIO
**/
cRadio::cRadio(float frec, TipoDeBanda band, bool on_off)
{
    frecuencia = frec;
    banda = band;
    prendido = on_off;
}
void cRadio::setPrendido(bool on_off)
{
    prendido = on_off;
}

void cRadio::setBanda(TipoDeBanda band)
{
    banda = band;
}
void cRadio::setFrecuencia(float f)
{
    frecuencia = f;
}


/***
** CRADIORELOJ
**/
///cTime time;
///char *marca;

///radio
///float frecuencia;
///TipoDeBanda banda;
///bool prendido;
cRadioReloj::cRadioReloj(cTime un_tiempo, cTime otro_tiempo, TipoAlarma alar)
{

    time = un_tiempo;
    alarma = otro_tiempo;
    tipo = alar;

    prendido = false;
    setFrecuencia(100.1);
    setBanda(FM);


}
cRadioReloj::cRadioReloj(cTime un_tiempo)
{

    time = un_tiempo;
    alarma.set_hora(0);
    alarma.set_minuto(0);
    alarma.set_segundo(0);

    tipo = Timbre;
    prendido = true;
    setFrecuencia(100.1);
    setBanda(FM);
    setPrendido(false);
}

void cRadioReloj::setAlarma(int h, int m, int s)
{

    alarma.set_hora(h);
    alarma.set_minuto(m);
    alarma.set_segundo(s);
}
void cRadioReloj::incrementarTiempo()
{

    alarma.set_hora(alarma.get_hora()+1);

}
cTime cRadioReloj::getTiempo()
{
    return alarma;
}

bool cRadioReloj::verificarAlarma()
{
    return prendido;
}
void cRadioReloj::setPrendido(bool on_off)
{
    prendido = on_off;
}
