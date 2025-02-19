#ifndef DIALOGELIMINARCLIENTE_H
#define DIALOGELIMINARCLIENTE_H

#include <QDialog>

namespace Ui {
class DialogEliminarCliente;
}

class DialogEliminarCliente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEliminarCliente(QWidget *parent = nullptr);
    ~DialogEliminarCliente();
    QString obtenerTelefono() const;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::DialogEliminarCliente *ui;
};

#endif // DIALOGELIMINARCLIENTE_H
