#include "pedidonormal.h"

PedidoNormal::PedidoNormal(int id, const QString &material, int cantidad, double costo, double ganancia)
    : Pedidos(id, material, cantidad, costo, ganancia) {}

QString PedidoNormal::detallePedido() const {
    return "Pedido Normal - Material: " + getMaterial() + ", Cantidad: " + QString::number(getCantidadMaterial());
}
