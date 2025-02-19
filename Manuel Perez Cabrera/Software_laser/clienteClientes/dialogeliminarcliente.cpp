#include "dialogeliminarcliente.h"
#include "ui_dialogeliminarcliente.h"

DialogEliminarCliente::DialogEliminarCliente(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogEliminarCliente)
{
    ui->setupUi(this);
}

DialogEliminarCliente::~DialogEliminarCliente()
{
    delete ui;
}

QString DialogEliminarCliente::obtenerTelefono() const
{
    return ui->lineEdit_Telefono->text();
}

void DialogEliminarCliente::on_pushButton_clicked()
{
     accept();
}


void DialogEliminarCliente::on_pushButton_2_clicked()
{
    reject();
}

