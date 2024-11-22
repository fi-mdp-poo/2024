#ifndef TRABAJOPINTURA_H
#define TRABAJOPINTURA_H

#include "Servicio.h"

class TrabajoPintura: public Servicio
{
    public:
        TrabajoPintura();
        virtual ~TrabajoPintura();

    protected:

    private:
        float superficie;
        float precio_pintura;
};

#endif // TRABAJOPINTURA_H
