#ifndef RECONOCIMIENTO_H
#define RECONOCIMIENTO_H

#include <QDebug>
#include "dlgimage.h"
#include "utility"
#include "vector"
#include "hu.h"


class reconocimiento
{
public:
    reconocimiento();
    void setImagen(dlgImage * imagen);
    void doReconocimiento();
private:
    dlgImage *img;
    hu *objHu;
    double A[8][8];
    double B[8][8];
};

#endif // RECONOCIMIENTO_H
