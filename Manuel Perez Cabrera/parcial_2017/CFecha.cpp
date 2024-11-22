#include "CFecha.h"

CFecha::CFecha(int d,int m,int a)
{
    //ctor
}


CFecha::~CFecha()
{
    //dtor
}

ostream& operator<< (ostream& co, CFecha& cmp)
{
    co<< cmp.GetDay() << "/" <<cmp.GetMonth() << "/" << cmp.GetYear();
    co<< endl;
}
