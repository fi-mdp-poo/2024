#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "pedidos.h"  // Incluimos la clase base

class PedidoEspecial : public Pedidos {
public:
    PedidoEspecial(int id, const QString &material, int cantidad, double costo, double ganancia, double descuento);

    // Implementación del método virtual puro de la clase base
    QString detallePedido() const override;
    double getDescuento()const ;

private:
    double descuento;  // Nuevo atributo específico para pedidos especiales
};

#endif // PEDIDOESPECIAL_H
