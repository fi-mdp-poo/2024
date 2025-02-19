#include "registerdialog.h"
#include "ui_registerdialog.h"



#include <QMessageBox>
#include <QFile>
#include <QTextStream>

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

#include <QStandardPaths>
#include <QDir>

void RegisterDialog::on_pushButton_Register_clicked()
{
    QString username = ui->lineEdit_Username->text();  // Obtener el nombre de usuario
    QString password = ui->lineEdit_Password->text();  // Obtener la contraseña

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, ingrese un nombre de usuario y una contraseña.");
        return;
    }

    // Obtener la ruta de Documentos y crear la carpeta si no existe
    QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

    QDir dir(carpetaDestino);
    if (!dir.exists()) {
        dir.mkpath(".");  // Crear la carpeta si no existe
    }

    // Ruta del archivo de usuarios
    QString rutaArchivoUsuarios = carpetaDestino + "/users.txt";

    // Verificar si el usuario ya existe en el archivo
    QFile file(rutaArchivoUsuarios);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de usuarios.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 2 && parts[0] == username) {
            QMessageBox::warning(this, "Error", "El usuario ya existe.");
            file.close();
            return;
        }
    }
    file.close();

    // Si el usuario no existe, lo agregamos
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escritura.");
        return;
    }

    QTextStream out(&file);
    out << username << "," << password << "\n";  // Escribir el nuevo usuario en el archivo
    file.close();

    QMessageBox::information(this, "Éxito", "Usuario registrado correctamente.");
    accept();  // Cerrar el diálogo si el registro fue exitoso
}




void RegisterDialog::on_pushButton_RCancel_clicked()
{
     reject();  // Cerrar el diálogo si se presiona "Cancelar"
}

