#ifndef CRELOJ_H
#define CRELOJ_H

#include <cstddef>
#include <string.h>
using namespace std;
#include <iostream>

class cTime
{
protected:
 unsigned int hora;
 unsigned int minuto;
 unsigned int segundo;
 public:
     cTime(int=0,int=0,int=0);
     friend ostream& operator<< (ostream&, const cTime&);


 void set_hora(int);
void set_minuto(int);
void set_segundo(int);
int get_hora();

};

class cReloj
{
protected:
 cTime time;
 char *marca;
 public:
    cReloj(cTime);
    ~cReloj();
    cReloj(int=0,int=0,int=0);
    void setTiempo(int,int,int);
    cTime getTiempo();
    void setMarca(const char*);
};

enum TipoDeBanda {AM, FM};
class cRadio
{
protected:
 float frecuencia;
 TipoDeBanda banda;
 bool prendido;
 public:
 bool is_prendido();
 cRadio(float=95.5, TipoDeBanda=FM, bool=false);
 void setPrendido(bool on_off);
 void setBanda(TipoDeBanda);
 void setFrecuencia(float);

};
enum TipoAlarma {Musica, Timbre};


class cRadioReloj: public cRadio, public cReloj
{
private:
 cTime alarma;
 TipoAlarma tipo;
 bool prendido;

 public:
 cRadioReloj(cTime, cTime, TipoAlarma = Timbre);
 cRadioReloj(cTime);
 void setPrendido(bool);

 void incrementarTiempo();
 void setAlarma(int, int, int);
  cTime getTiempo();
  bool verificarAlarma();

};
 ///cTime time;
 ///char *marca;

 ///radio
 ///float frecuencia;
 ///TipoDeBanda banda;
 ///bool prendido;

#endif // CRELOJ_H
