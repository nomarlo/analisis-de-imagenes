#ifndef RANGOS_H
#define RANGOS_H

#include <QWidget>
#include <QDebug>
#include "dlgimage.h"
#include "histograma.h"

namespace Ui {
class rangos;
}

class rangos : public QWidget
{
    Q_OBJECT

public:
    explicit rangos(QWidget *parent = 0);
    ~rangos();
    void setImagen(dlgImage * img, histograma *hist);

private:
    Ui::rangos *ui;
    dlgImage *img;
    histograma *hist;

public slots:
    void setRangos();
};

#endif // RANGOS_H
