#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QDateTime>
#include <QStandardPaths>
#include <QDir>

namespace Ui {
class logindialog;
}

class logindialog : public QDialog
{
    Q_OBJECT

public:
    explicit logindialog(QWidget *parent = nullptr);
    ~logindialog();
    QString getUsuarioActual() const;  // Nueva función
    bool verificarUsuario(const QString &username, const QString &password);
    void registrarUsuario();

private slots:
    void on_pushButton_Login_clicked();
    void on_pushButton_Cancel_clicked();

private:

    Ui::logindialog *ui;
    QString usuarioActual;
};

#endif // LOGINDIALOG_H
