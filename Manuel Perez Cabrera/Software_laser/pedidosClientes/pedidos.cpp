#include "pedidos.h"

Pedidos::Pedidos(int id, const QString &material, int cantidad, double costo, double ganancia)
    : id(id), material(material), cantidadMaterial(cantidad), costoMaterial(costo), ganancia(ganancia)
{
}

int Pedidos::getId() const
{
    return id;
}

QString Pedidos::getMaterial() const
{
    return material;
}

int Pedidos::getCantidadMaterial() const
{
    return cantidadMaterial;
}

double Pedidos::getCostoMaterial() const
{
    return costoMaterial;
}

double Pedidos::getGanancia() const
{
    return ganancia;
}
// Setters
void Pedidos::setId(int newId)
{
    id = newId;
}
void Pedidos::setMaterial(const QString &newMaterial)
{
    material = newMaterial;
}
void Pedidos::setCantidadMaterial(int newCantidad)
{
    cantidadMaterial = newCantidad;
}
void Pedidos::setCostoMaterial(double newCosto)
{
    costoMaterial = newCosto;
}
void Pedidos::setGanancia(double newGanancia)
{
    ganancia = newGanancia;
}

// Implementación de obtenerDescripcion()
QString Pedidos::obtenerDescripcion() const {
    return "ID: " + QString::number(id) + "\n" +
           "Material: " + material + "\n" +
           "Cantidad: " + QString::number(cantidadMaterial) + "\n" +
           "Costo: " + QString::number(costoMaterial) + "\n" +
           "Ganancia: " + QString::number(ganancia);
}
