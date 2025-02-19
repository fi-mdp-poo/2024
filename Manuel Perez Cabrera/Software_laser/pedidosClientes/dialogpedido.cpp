#include "dialogpedido.h"
#include "ui_dialogpedido.h"

DialogPedido::DialogPedido(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPedido)
{
    ui->setupUi(this);
    ui->label_3->hide();  // Ocultar el layout si el checkbox no está marcado
    ui->doubleSpinBoxDescuento->hide();
}

DialogPedido::~DialogPedido()
{
    delete ui;
}

QString DialogPedido::getMaterial() const {
    return ui->lineEditMaterial->text();
}

int DialogPedido::getCantidadMaterial() const {
    return ui->spinBoxMaterial->value();
}

double DialogPedido::getCostoMaterial() const {
    return ui->spinBoxMaterial->value() * ui->doubleSpinBox_2->value();
}

double DialogPedido::getGanancia() const
{
    if(ui->checkBoxPedidoEspecial->isChecked())
    {
         return (ui->doubleSpinBox->value() - (ui->spinBoxMaterial->value() * ui->doubleSpinBox_2->value())-ui->doubleSpinBoxDescuento->value());
    }
    return ui->doubleSpinBox->value() - (ui->spinBoxMaterial->value() * ui->doubleSpinBox_2->value());

}

void DialogPedido::on_pushButton_clicked()
{
    if (getMaterial().isEmpty()) {
        QMessageBox::warning(this, "Error", "El material del pedido no puede estar vacío.");
        return;
    }

    accept();
}

bool DialogPedido::esPedidoEspecial() const {
    return ui->checkBoxPedidoEspecial->isChecked();    // Devuelve true si está marcado

}

double DialogPedido::getDescuento() const {
    return ui->doubleSpinBoxDescuento->value();   // Suponiendo que hay un QDoubleSpinBox para descuento
}


void DialogPedido::on_checkBoxPedidoEspecial_toggled(bool checked)
{
    if (checked) {
        ui->label_3->show();  // Mostrar el layout si el checkbox está marcado
        ui->doubleSpinBoxDescuento->show();

    } else {
        ui->label_3->hide();  // Ocultar el layout si el checkbox no está marcado
        ui->doubleSpinBoxDescuento->hide();
    }
}

