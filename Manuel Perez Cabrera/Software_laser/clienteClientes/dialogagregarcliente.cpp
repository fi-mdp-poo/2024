#include "dialogagregarcliente.h"
#include "ui_dialogagregarcliente.h"

DialogAgregarCliente::DialogAgregarCliente(GestorClientes &gestor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAgregarCliente),
    gestorClientes(gestor)  // Inicializamos la referencia al gestor
{
    ui->setupUi(this);
}

DialogAgregarCliente::~DialogAgregarCliente()
{
    delete ui;
}

Cliente DialogAgregarCliente::obtenerCliente() const {
    // Obtener los datos desde la interfaz de usuario (QLineEdits, etc.)
    QString nombre = ui->lineEdit_Nombre->text();
    QString apellido = ui->lineEdit_Apellido->text();
    QString telefono = ui->lineEdit_Telefono->text();
    QString email = ui->lineEdit_Email->text();
    QString direccion = ui->lineEdit_Direccion->text();

    // Crear y devolver el cliente
    return Cliente(nombre, apellido, telefono, email, direccion);
}
void DialogAgregarCliente::on_buttonBox_accepted()
{
    // Crear el cliente con los datos del formulario
    QString nombre = ui->lineEdit_Nombre->text();
    QString apellido = ui->lineEdit_Apellido->text();
    QString telefono = ui->lineEdit_Telefono->text();
    QString email = ui->lineEdit_Email->text();
    QString direccion = ui->lineEdit_Direccion->text();

    // Crear el cliente
    Cliente* nuevoCliente = new Cliente(nombre, apellido, telefono, email, direccion);

    // Agregar el cliente al gestor
    gestorClientes.agregarCliente(nuevoCliente);

    // Cerrar el diálogo
    accept();
}


