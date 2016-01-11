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

public slots:
    void doOtsu();
};

#endif // OTSU_H
