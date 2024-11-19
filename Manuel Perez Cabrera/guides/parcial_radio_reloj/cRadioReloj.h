#ifndef CRADIORELOJ_H
#define CRADIORELOJ_H
#include "cRadio.h"
#include "cReloj.h"

enum TipoAlarma {Musica, Timbre};

class cRadioReloj: public cRadio, public cReloj
{

public:
    cRadioReloj(cTime =cTime(23,59,59),cTime =cTime(0,0,0),TipoAlarma t = Timbre,bool alarm = false , float band = 100.1,TipoDeBanda tipp = FM , bool rad = false);
    ~cRadioReloj();

    void setAlarma(int, int, int);

protected:
    cTime alarma;
    TipoAlarma tipo;
    bool prendido;

};

#endif // CRADIORELOJ_H
