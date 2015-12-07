#ifndef CONVOLUCION_H
#define CONVOLUCION_H

#include <QWidget>
#include <QStandardItemModel>
#include "dlgimage.h"

namespace Ui {
class convolucion;

}

class convolucion : public QWidget
{
    Q_OBJECT

public:
    explicit convolucion(QWidget *parent = 0);
    ~convolucion();
    void setImagen(dlgImage * img);

private:
    Ui::convolucion *ui;
    QStandardItemModel *model;
    int t;
    int x,y; //coordenadas de la celda seleccionada
    dlgImage *img;

public slots:
    void doCon();
    void setGrid();

};

#endif // CONVOLUCION_H
