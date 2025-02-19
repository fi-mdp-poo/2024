#include "dialogeliminarproducto.h"
#include "ui_dialogeliminarproducto.h"

DialogEliminarProducto::DialogEliminarProducto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogEliminarProducto)
{
    ui->setupUi(this);
}

DialogEliminarProducto::~DialogEliminarProducto()
{
    delete ui;
}

QString DialogEliminarProducto::getNombreProducto() const
{
    return ui->lineEdit_NombreProducto->text();  // Obtener el nombre ingresado
}


