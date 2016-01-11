#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class histograma;
}

class histograma : public QWidget
{
    Q_OBJECT

public:
    explicit histograma(QWidget *parent = 0);
    ~histograma();
    void setDatos(QPixmap pixmap);
    QVector<double> *R, *G, *B, *Gr, *X;

private:
    Ui::histograma *ui;
    void Dibujar(QCustomPlot *customPlot);




public slots:
    void ReDibujar();
};

#endif // HISTOGRAMA_H
