#include "ManejadorColor.h"

ManejadorColor::ManejadorColor( CColor color)
{
    un_color = color;
}

ManejadorColor::~ManejadorColor()
{
    //dtor
}


CColor& ManejadorColor::getColor()
{
    return un_color;
}

void ManejadorColor::setColor(uint32_t c){
    un_color.setColor(c);

}
