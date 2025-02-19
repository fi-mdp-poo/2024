#include "logindialog.h"
#include "ui_logindialog.h"


logindialog::logindialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::logindialog)
{
    ui->setupUi(this);
   // ui->lineEdit_Username->setEchoMode(QLineEdit::Password);

}

logindialog::~logindialog()
{
    delete ui;
}

/*************************************************************/
QString logindialog::getUsuarioActual() const {
    return usuarioActual;
}




bool logindialog::verificarUsuario(const QString &username, const QString &password)
{
    // Obtener la ruta de Documentos y la carpeta donde se guardan los archivos
    QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

    // Ruta del archivo de usuarios
    QString rutaArchivoUsuarios = carpetaDestino + "/users.txt";

    QFile file(rutaArchivoUsuarios);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de usuarios.");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // Eliminamos espacios en blanco
        QStringList parts = line.split(",");

        if (parts.size() == 2) {
            QString storedUser = parts[0].trimmed();
            QString storedPass = parts[1].trimmed();

            if (username == storedUser && password == storedPass) {
                file.close();
                return true; // Usuario y contraseña coinciden
            }
        }
    }

    file.close();
    return false; // No se encontró el usuario o la contraseña es incorrecta
}


/********************************/
/*
void logindialog::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (verificarUsuario(username, password)) {
        QMessageBox::information(this, "Login", "Inicio de sesión exitoso.");
        usuarioActual = username; // Guardamos el usuario que inició sesión

        accept();  // Cierra el diálogo correctamente y devuelve Accepted
    } else {
        QMessageBox::warning(this, "Login", "Usuario o contraseña incorrectos.");
    }
}
*/


void logindialog::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (verificarUsuario(username, password)) {
        usuarioActual = username; // Guardamos el usuario que inició sesión
        QMessageBox::information(this, "Login", "Inicio de sesión exitoso.");

        // Obtener la ruta base de Documentos
        QString rutaBase = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        QString carpetaDestino = rutaBase + "/softwarelaserArchivos";

        // Crear la carpeta si no existe
        QDir().mkpath(carpetaDestino);

        // Definir la ruta del archivo de logins
        QString rutaLogins = carpetaDestino + "/logins.txt";

        // Registrar el ingreso en el archivo de logins
        QFile file(rutaLogins);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);

            // Obtener la fecha y hora actuales
            QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

            // Escribir en el archivo: nombre de usuario y fecha de login
            out << "User: " << username << ", " << currentDateTime << "\n";

            file.close(); // Cerrar el archivo
        } else {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de logins.");
        }

        accept();  // Cierra el diálogo correctamente y devuelve Accepted
    } else {
        QMessageBox::warning(this, "Login", "Usuario o contraseña incorrectos.");
    }
}



/*
void logindialog::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (verificarUsuario(username, password)) {
        usuarioActual = username; // Guardamos el usuario que inició sesión
        QMessageBox::information(this, "Login", "Inicio de sesión exitoso.");

        accept();  // Cierra el diálogo correctamente y devuelve Accepted
    } else {
        QMessageBox::warning(this, "Login", "Usuario o contraseña incorrectos.");
    }
}

*/


void logindialog::on_pushButton_Cancel_clicked()
{
    reject();  // Cierra el diálogo y devuelve QDialog::Rejected
}



