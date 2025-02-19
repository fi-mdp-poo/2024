#ifndef DIALOGAGREGARPRODUCTO_H
#define DIALOGAGREGARPRODUCTO_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DialogAgregarProducto;
}

class DialogAgregarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAgregarProducto(QWidget *parent = nullptr);
    ~DialogAgregarProducto();
    QString getNombre() const;
    int getCantidad() const;
    double getPrecio() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAgregarProducto *ui;
};

#endif // DIALOGAGREGARPRODUCTO_H
