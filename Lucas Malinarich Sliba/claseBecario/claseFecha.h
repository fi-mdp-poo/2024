#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    unsigned int day, month, year;
public:
    Fecha(unsigned dd=0, unsigned mm=0, unsigned yy=0);
    virtual ~Fecha();
    void setDay(unsigned int);
    void setMonth(unsigned int);
    void setYear(unsigned int);
    unsigned int getDay()const;
    unsigned int getMonth()const;
    unsigned int getYear()const;
};

#endif // CLASEFECHA_H_INCLUDED
