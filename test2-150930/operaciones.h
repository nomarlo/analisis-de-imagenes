#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <QWidget>
#include "dlgimage.h"

namespace Ui {
class operaciones;
}

class operaciones : public QWidget
{
    Q_OBJECT

public:
    explicit operaciones(QWidget *parent = 0);
    ~operaciones();    
    void setImagenes(dlgImage * imagen, dlgImage * imagen2);

private:
    Ui::operaciones *ui;
    dlgImage *img;
    dlgImage *img2;

public slots:
    void doOp();
};

#endif // OPERACIONES_H
