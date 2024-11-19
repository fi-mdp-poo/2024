#include "CColor.h"

CColor::CColor()
{
    //ctor
}

CColor::~CColor()
{
    //dtor
}


        CColor::CColor(int c)
{
    color = c;
    a = (c & 0xFF000000)>> 3*8;
    r = (c & 0x000000FF)>> 0*8;
    g = (c & 0x0000FF00)>> 1*8;
    b = (c & 0x00FF0000)>> 2*8;

}

        unsigned char CColor::GetRed(){
        return r;
        }
        unsigned char CColor::GetGreen(){
        return g;
        }
        unsigned char CColor::GetBlue(){
        return b;
        }
        unsigned char CColor::GetAlpha(){
        return a;
        }
        int CColor::GetColor(){
        return color;
        }
        void CColor::SetRed(unsigned char red){
        r = red;
        }
        void CColor::SetGreen(unsigned char green){
        g = green;
        }
        void CColor::SetBlue(unsigned char blue){
        b = blue;

        }
        void CColor::SetAlpha(unsigned char alpha){
        a = alpha;
        }
        void CColor::SetColor(int color){
        color = color;
        }
        ostream& operator<< (ostream& os, CColor c){
        os << "componente rojo:" <<  (int)(c.GetRed()) << endl;
        os << "componente verde:" << (int)(c.GetGreen()) << endl;
        os << "componente azul:" << (int)(c.GetBlue()) << endl;
        os << "componente alpha:" << (int)(c.GetAlpha()) << endl;

        return os;
        }
