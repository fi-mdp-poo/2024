#ifndef DIALOGAGREGARCLIENTE_H
#define DIALOGAGREGARCLIENTE_H

#include <QDialog>
#include "cliente.h"
#include "gestorclientes.h"  // Incluir GestorClientes

namespace Ui {
class DialogAgregarCliente;
}

class DialogAgregarCliente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAgregarCliente(GestorClientes &gestor, QWidget *parent = nullptr);  // Agregar referencia al gestor
    ~DialogAgregarCliente();
    Cliente obtenerCliente() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAgregarCliente *ui;
    GestorClientes &gestorClientes;  // Referencia al GestorClientes
};

#endif // DIALOGAGREGARCLIENTE_H
