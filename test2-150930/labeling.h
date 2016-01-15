#ifndef LABELING_H
#define LABELING_H

#include <QWidget>
#include "dlgimage.h"
#include "stack"
#include "utility"

namespace Ui {
class labeling;
}

class labeling : public QWidget
{
    Q_OBJECT

public:
    explicit labeling(QWidget *parent = 0);
    ~labeling();
    dlgImage *img;
    void setImagen(dlgImage * imagen);
    void preCargaImagen();

private:
    Ui::labeling *ui;
    int color;//color a buscar 0 blanco, 1 negro
    int vecindad;//tamaño de la vecindad 4 u 8
    int h, wi;
    int MImagen[2048][2048];
    std::stack < std::pair <int,int> > P;

public slots:
    void doLabeling();
};

#endif // LABELING_H
