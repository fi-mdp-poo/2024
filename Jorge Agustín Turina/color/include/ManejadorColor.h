#ifndef MANEJADORCOLOR_H
#define MANEJADORCOLOR_H

#include "CColor.h"
class ManejadorColor
{
    public:
        ManejadorColor(CColor = CColor(244,28,0,244));
        virtual ~ManejadorColor();
        CColor& getColor();
        void setColor(uint32_t);

    protected:

    private:
        CColor un_color;
};

#endif // MANEJADORCOLOR_H
