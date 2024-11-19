#include "CColor.h"

CColor::CColor(unsigned int  color)
{
    blue = (color & 0xFF);
    green = (color & 0x0000FF00) >>8;
    red = (color & 0x00FF0000)>> 16;
    alpha = (color & 0xFF000000)>>24;
}

CColor::~CColor()
{
    //dtor
}


ostream& operator<<(ostream& os, const CColor& color)
{
    os<< " A: " << setw(2) << color.alpha<<endl;
    os<< " R: " << setw(2) << color.red<<endl;
    os<< " G: " << setw(2) << color.green<<endl;
    os<< " B: " << setw(2) << color.blue<<endl;

    return os;
}
