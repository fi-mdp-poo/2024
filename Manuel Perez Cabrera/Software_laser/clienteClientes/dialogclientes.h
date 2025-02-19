#ifndef DIALOGCLIENTES_H
#define DIALOGCLIENTES_H

#include <QDialog>
#include <QTableWidget>
#include "gestorclientes.h"

namespace Ui {
class DialogClientes;
}

class DialogClientes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClientes(GestorClientes &gestor, QWidget *parent = nullptr);
    ~DialogClientes();
    void actualizarTabla();

private slots:

    void on_pushButton_Agregar_clicked();
    void on_pushButton_Eliminar_clicked();

private:
    Ui::DialogClientes *ui;
    GestorClientes &gestorClientes;

};

#endif // DIALOGCLIENTES_H
