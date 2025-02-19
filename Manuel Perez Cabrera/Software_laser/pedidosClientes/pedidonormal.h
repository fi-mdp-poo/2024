#ifndef PEDIDONORMAL_H
#define PEDIDONORMAL_H

#include "pedidos.h"  // Incluimos la clase base

class PedidoNormal : public Pedidos {
public:
    PedidoNormal(int id, const QString &material, int cantidad, double costo, double ganancia);

    // Implementación del método virtual puro de la clase base
    QString detallePedido() const override;
};

#endif // PEDIDONORMAL_H
