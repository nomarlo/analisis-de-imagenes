#ifndef DISTANCE_H
#define DISTANCE_H
#include "dlgimage.h"
#include <QWidget>

namespace Ui {
class distance;
}

class distance : public QWidget
{
    Q_OBJECT

public:
    explicit distance(QWidget *parent = 0);
    ~distance();
    dlgImage *img;
    void setImagen(dlgImage * imagen);
    void preCargaImagen();

private:
    Ui::distance *ui;
    int color;//color a buscar 0 blanco, 1 negro
    int vecindad;//tamaño de la vecindad 4 u 8
    int h, wi;
    int MImagen[2048][2048];

public slots:
    void doTransformacion();
};

#endif // DISTANCE_H
