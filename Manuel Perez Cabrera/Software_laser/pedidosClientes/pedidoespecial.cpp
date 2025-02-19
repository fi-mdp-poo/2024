#include "pedidoespecial.h"

PedidoEspecial::PedidoEspecial(int id, const QString &material, int cantidad, double costo, double ganancia, double descuento)
    : Pedidos(id, material, cantidad, costo, ganancia), descuento(descuento) {}

QString PedidoEspecial::detallePedido() const {
    return "Pedido Especial - Material: " + getMaterial() + ", Cantidad: " + QString::number(getCantidadMaterial()) +
           ", Descuento: " + QString::number(descuento);
}

double PedidoEspecial::getDescuento() const
{
    return descuento;
}
