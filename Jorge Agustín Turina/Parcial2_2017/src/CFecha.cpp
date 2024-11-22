#include "CFecha.h"

CFecha::CFecha()
 {

 }
CFecha::CFecha(int d, int m, int y)
{
    SetDay(d);
    SetMonth(m);
    SetYear(y);
}

CFecha::~CFecha()
{
    //dtor
}

ostream& operator<< (ostream& co, CFecha &cmp)
{
    int dia=cmp.GetDay();
    int mes=cmp.GetMonth();
    int ano=cmp.GetYear();
    co<< dia << "/" << mes << "/" << ano <<endl;
    return co;
}
