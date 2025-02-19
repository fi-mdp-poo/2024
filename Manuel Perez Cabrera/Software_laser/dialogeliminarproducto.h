#ifndef DIALOGELIMINARPRODUCTO_H
#define DIALOGELIMINARPRODUCTO_H

#include <QDialog>

namespace Ui {
class DialogEliminarProducto;
}

class DialogEliminarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEliminarProducto(QWidget *parent = nullptr);
    ~DialogEliminarProducto();
    QString getNombreProducto() const;  // Método para obtener el nombre del producto



private:
    Ui::DialogEliminarProducto *ui;
};

#endif // DIALOGELIMINARPRODUCTO_H
