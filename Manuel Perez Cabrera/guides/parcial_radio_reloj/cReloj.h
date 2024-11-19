#ifndef CRELOJ_H
#define CRELOJ_H
#include "cTime.h"

class cReloj
{
public:
    cReloj(int hora  ,int minutos ,int segundos );
    cReloj(cTime = cTime(0,0,0),char* marca = "default");
    ~cReloj();
///setter and getters

    void setTiempo(int ,int ,int);
    void setMarca(char*);
    cTime getTiempo();



protected:
    cTime time;
    char *marca;

};

#endif // CRELOJ_H
