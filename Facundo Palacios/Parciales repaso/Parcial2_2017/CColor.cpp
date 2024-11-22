#include "CColor.h"
#include <iomanip>

CColor::CColor(int Color)
{
    SetColor(Color);
    Blue = (Color & 0xFF);
    Green = (Color & 0x0000FF00) >>8;
    Red = (Color & 0x00FF0000)>> 16;
    Alpha = (Color & 0xFF000000)>>24;
}

CColor::~CColor()
{
    //dtor
}

void CColor::SetBlue(int val)
{
    Blue = val;
    int aux = GetColor();
    aux &= 0xFFFFFF00;          // Limpiar el cuarto byte (Blue)
    aux |= val;                 // Establecer el nuevo valor para Blue
    SetColor(aux);

}

void CColor::SetGreen(int val)
{
    Green = val;
    int aux = GetColor();
    aux &= 0xFFFF00FF;          // Limpiar el tercer byte (Green)
    aux |= (val << 8);          // Establecer el nuevo valor para Green
    SetColor(aux);

}

void CColor::SetRed(int val)
{
    Red = val;
    int aux = GetColor();
    val = val << 16;
    aux = aux & 0xFF00FFFF;
    aux = aux | val ;

    SetColor(aux);

}

void CColor::SetAlpha(int val)
{
    Alpha=val;

}

ostream& operator<< (ostream& co, CColor &cmp)
{
    co<<"Color:"<<showbase<<hex<<cmp.GetColor();
    co<<dec<< "(rojo="<<cmp.GetRed()<<",verde="<<cmp.GetGreen()<<",azul="<<cmp.GetBlue()<<",alpha="<<cmp.GetAlpha()<<")"<<endl;
    return co;
}
