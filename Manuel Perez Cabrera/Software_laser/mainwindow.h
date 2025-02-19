#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestionStock.h"
#include "producto.h"
#include "clienteClientes/dialogclientes.h"
#include "pedidosClientes/gestorpedidos.h"
//#include "/dialogpedido.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //MainWindow(QWidget *parent = nullptr);
    MainWindow(const QString &usuario, QWidget *parent = nullptr);
    ~MainWindow();
    void setUsuarioActual(const QString &usuario);
    QString getUsuarioActual() const;
    void actualizarTabla();
    void actualizarTablaPedidos();
    void cargarPedidosEnTabla();   // Método para cargar los pedidos en el QTableWidget

private slots:
    void on_actionRegister_triggered();

    void on_actionLogOut_triggered();

    void on_actionAgregar_Producto_triggered();

    void on_actionEliminar_Producto_triggered();

    void on_actionGestionar_Clientes_triggered();

    void on_actionAgregar_Pedido_triggered();

private:

    Ui::MainWindow *ui; //apunta a un objeto que gestiona la interfaz grafica
    QString usuarioActual;
    GestionStock gestionStock;
    GestorClientes gestorClientes;
    GestorPedidos gestorPedidos;

};

#endif // MAINWINDOW_H
