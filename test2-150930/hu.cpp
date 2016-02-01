#include "hu.h"
#include "math.h"

hu::hu()
{

}

void hu::setImagen(dlgImage *imagen){
    img=imagen;
}

void hu::preCargaImagen(){
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();

    int wi= pixm->width();
    int h= pixm->height();

    for(int i=0;i<h;i++){
        for(int j=0;j<wi;j++){
            if(qGray(imagen.pixel(j,i))==0)//objetos negros
                P.push_back(std::make_pair(j,i));

        }
    }
    //centro
    xc=(getM(1,0)/getM(0,0));
    yc=(getM(0,1)/getM(0,0));

}

long long int hu::getM(int pe, int q){
    long long int m=0;
    for(int i=0;i<P.size();i++){
        m+=pow(P[i].first,pe)*pow(P[i].second,q);
    }
    return m;
}

long long int hu::getM2(int pe, int q){
    long long int m=0;

    for(int i=0;i<P.size();i++){
        m+=pow((P[i].first-xc),pe)*pow((P[i].second-yc),q);
    }

    return m;
}

double hu::getN(int pe, int q){
    return pe+q>=2?(double)((double)getM2(pe,q)/(double)pow(getM2(0,0),pe+q)):0;
}

std::vector<double> hu::getHu(){
        std::vector<double> H;

        H.push_back(getN(2,0)+getN(0,2));
        H.push_back(pow(getN(2,0)-getN(0,2),2)+4*pow(getN(1,1),2));
        H.push_back(pow(getN(3,0)-3*getN(1,2),2)+pow(3*getN(2,1)-getN(0,3),2));
        H.push_back(pow(getN(3,0)+getN(1,2),2)+(pow(getN(2,1)+getN(0,3),2)));

        return H;
}
