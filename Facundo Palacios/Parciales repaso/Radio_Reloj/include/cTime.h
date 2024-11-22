#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED

class cTime
{
public:
    cTime(int hora = 0, int minutos = 0, int segundos = 0);
    //cTime(const cTime&);
    virtual ~cTime();
    void Set_hora( int );
    void Set_minutos( int );
    void Set_segundos( int );

protected:
    int hora;
    int minutos;
    int segundos;


private:
};

#endif // CTIME_H_INCLUDED
