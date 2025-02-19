#include "dialogclientes.h"
#include "ui_dialogclientes.h"
#include "dialogagregarcliente.h"
#include "dialogeliminarcliente.h"

DialogClientes::DialogClientes(GestorClientes &gestor, QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogClientes), gestorClientes(gestor)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Nombre", "Apellido", "Teléfono", "Email", "Direccion"});

    actualizarTabla();
}

DialogClientes::~DialogClientes()
{
    delete ui;
}

void DialogClientes::actualizarTabla()
{
    ui->tableWidget->setRowCount(0);  // Limpiar la tabla antes de agregar los nuevos datos

    QList<Cliente*> listaClientes = gestorClientes.obtenerClientes();
    for (Cliente* c : listaClientes) {  // Iterar sobre los punteros a Cliente
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Usar los getters para obtener los datos de los objetos Cliente
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(c->getNombre()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c->getApellido()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c->getTelefono()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(c->getEmail()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(c->getDireccion()));
    }
}




void DialogClientes::on_pushButton_Agregar_clicked()
{
    DialogAgregarCliente dialog(gestorClientes,this);
    if (dialog.exec() == QDialog::Accepted) {
        Cliente nuevoCliente = dialog.obtenerCliente();
        //gestorClientes.agregarCliente(nuevoCliente);
        actualizarTabla();
    }
}


void DialogClientes::on_pushButton_Eliminar_clicked()
{
    DialogEliminarCliente dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString telefono = dialog.obtenerTelefono();
        gestorClientes.eliminarCliente(telefono);
        actualizarTabla();
    }
}

