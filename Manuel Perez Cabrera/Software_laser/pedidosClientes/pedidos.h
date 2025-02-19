#ifndef PEDIDO_H
#define PEDIDO_H

#include <QString>

class Pedidos {
public:
    Pedidos(int id, const QString &material, int cantidad, double costo, double ganancia);

    virtual ~Pedidos() = default; // Destructor virtual

    // Métodos comunes
    int getId() const;
    QString getMaterial() const;
    int getCantidadMaterial() const;
    double getCostoMaterial() const;
    double getGanancia() const;
    void setId(int newId);
    void setMaterial(const QString &newMaterial);
    void setCantidadMaterial(int newCantidad);
    void setCostoMaterial(double newCosto);
    void setGanancia(double newGanancia);

    // Método virtual puro para polimorfismo
    virtual QString detallePedido() const = 0;
    // Método que proporciona una descripción general del pedido
    virtual QString obtenerDescripcion() const;


protected:
    int id;
    QString material;
    int cantidadMaterial;
    double costoMaterial;
    double ganancia;
};

#endif // PEDIDO_H
