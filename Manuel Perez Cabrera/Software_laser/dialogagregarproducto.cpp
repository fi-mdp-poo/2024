#include "dialogagregarproducto.h"
#include "ui_dialogagregarproducto.h"

DialogAgregarProducto::DialogAgregarProducto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAgregarProducto)
{
    ui->setupUi(this);
}

DialogAgregarProducto::~DialogAgregarProducto()
{
    delete ui;
}

QString DialogAgregarProducto::getNombre() const {
    return ui->lineEdit_Nombre->text();
}

int DialogAgregarProducto::getCantidad() const {
    return ui->spinBox_Cantidad->value();
}

double DialogAgregarProducto::getPrecio() const {
    return ui->doubleSpinBox_Precio->value();
}
void DialogAgregarProducto::on_buttonBox_accepted()
{
    if (getNombre().isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre del producto no puede estar vacío.");
        return;
    }

    accept();
}

