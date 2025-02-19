#ifndef DIALOGPEDIDO_H
#define DIALOGPEDIDO_H

#include <QDialog>
#include <QMessageBox>
#include "pedidos.h"

namespace Ui {
class DialogPedido;
}

class DialogPedido : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPedido(QWidget *parent = nullptr);
    ~DialogPedido();
    QString getMaterial() const;
    int getCantidadMaterial() const;
    double getCostoMaterial() const;
    double getGanancia() const;
    bool esPedidoEspecial() const; // Nueva función
    double getDescuento() const; // Para pedidos especiales

private slots:

    void on_pushButton_clicked();


    void on_checkBoxPedidoEspecial_toggled(bool checked);

private:
    Ui::DialogPedido *ui;
};

#endif // DIALOGPEDIDO_H
