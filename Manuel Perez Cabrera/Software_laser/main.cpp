#include "logindialog.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    logindialog login;


    if (login.exec() == QDialog::Accepted) {  // Si el login fue exitoso

        QString usuario = login.getUsuarioActual();// Obtener el usuario del login
        MainWindow *w = new MainWindow(usuario);  // Pasar usuario a MainWindow
        w->show();
        return a.exec();

    }

    return 0;  // Si el login falla, cerramos la app
}

