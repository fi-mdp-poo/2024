#include "CColor.h"

CColor::CColor(int col)
{
    SetColor(col);
    Blue = (col & 0xFF);
    Green = (col & 0x0000FF00) >>8;
    Red = (col & 0x00FF0000)>> 16;
    Alpha = (col & 0xFF000000)>>24;

}


ostream& operator<< (ostream& co, CColor &cmp)
{
    co<<"Color:"<<showbase<<hex<<cmp.GetColor();
    co<<dec<< "(rojo="<<cmp.GetRed()<<",verde="<<cmp.GetGreen()<<",azul="<<cmp.GetBlue()<<",alpha="<<cmp.GetAlpha()<<")"<<endl;
    return co;
}
