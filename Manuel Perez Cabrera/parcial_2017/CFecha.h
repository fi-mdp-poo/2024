#ifndef CFECHA_H
#define CFECHA_H
#include <iostream>

using namespace std;

class CFecha
{
public:
    CFecha(int Day = 0,int Month = 0,int Year = 0);

    virtual ~CFecha();

    int GetDay()
    {
        return Day;
    }
    void SetDay(int val)
    {
        Day = val;
    }
    int GetMonth()
    {
        return Month;
    }
    void SetMonth(int val)
    {
        Month = val;
    }
    int GetYear()
    {
        return Year;
    }
    void SetYear(int val)
    {
        Year = val;
    }


    ///hacer funcion de impresion
    friend ostream& operator<< (ostream& co, CFecha &cmp);

protected:

private:
    int Day;
    int Month;
    int Year;
};

#endif // CFECHA_H
