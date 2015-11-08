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
    void setDatos();


private:
    Ui::histograma *ui;
    void Dibujar(QCustomPlot *customPlot);
};

#endif // HISTOGRAMA_H
