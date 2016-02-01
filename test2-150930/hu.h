#ifndef HU_H
#define HU_H

#include "dlgimage.h"
#include "utility"
#include "vector"

class hu
{
public:
    hu();
    void setImagen(dlgImage * imagen);
    std::vector < std::pair <int,int> > P; //puntos del objeto
    void preCargaImagen(); //buscamos los puntos del objeto
    std::vector<double> getHu();
private:
    dlgImage *img;
    long long int getM(int pe, int q);
    long long int getM2(int pe, int q);
    double getN(int pe, int q);
    int xc, yc;
};

#endif // HU_H
