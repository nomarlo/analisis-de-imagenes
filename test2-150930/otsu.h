#ifndef OTSU_H
#define OTSU_H

#include <QWidget>
#include "dlgimage.h"
#include "histograma.h"

namespace Ui {
class Otsu;
}

class Otsu : public QWidget
{
    Q_OBJECT

public:
    explicit Otsu(QWidget *parent = 0);
    ~Otsu();
    void setImagen(dlgImage * img, histograma *hist);

private:
    Ui::Otsu *ui;
    histograma *hist;
    dlgImage *img;
    QVector<double> *Acumulado, *Acumulado2;
    void doAcumulado();
    void doOtsu(int t);

public slots:
    void setT();

};

#endif // OTSU_H
