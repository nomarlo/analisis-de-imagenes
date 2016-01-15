#include "labeling.h"
#include "ui_labeling.h"
#include <QDebug>
#include "iostream"


labeling::labeling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labeling)
{
    ui->setupUi(this);
}

labeling::~labeling()
{
    delete ui;
}

void labeling::setImagen(dlgImage *imagen){
    img=imagen;
}

void labeling::doLabeling(){

    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();

    int label =20;
    std::pair <int,int> C;

    color=ui->colores->currentIndex()==1?0:255;
    vecindad=ui->vecindades->currentIndex()==0?4:8;

    preCargaImagen();

    for(int x=0;x<wi;x++){
        for(int y=0;y<h;y++){
            if(MImagen[x][y]==color){
                P.push(std::make_pair(x,y));
                while(!P.empty()){
                    int x2,y2;

                    x2=P.top().first;
                    y2=P.top().second;

                    P.pop();

                    MImagen [x2][y2]=label;

                    //izquierda/arriba/derecha/abajo
                    if(x2-1>=0 && MImagen[x2-1][y2]==color)
                        P.push(std::make_pair(x2-1,y2));
                    if(y2-1>=0 && MImagen[x2][y2-1]==color)
                        P.push(std::make_pair(x2,y2-1));
                    if(x2+1<wi && MImagen[x2+1][y2]==color)
                        P.push(std::make_pair(x2+1,y2));
                    if(y2+1<h && MImagen[x2][y2+1]==color )
                        P.push(std::make_pair(x2,y2+1));


                    if(vecindad==8){
                        //Superior izquierda/Derecha/Inferior izquierda/derecha
                        if(x2-1>=0 && y2-1>=0 && MImagen[x2-1][y2-1]==color)
                            P.push(std::make_pair(x2-1,y2-1));
                        if(x2+1<=wi && y2-1>=0   && MImagen[x2+1][y2-1]==color)
                            P.push(std::make_pair(x2+1,y2-1));
                        if(x2-1<=0 && y2+1<h && MImagen[x2-1][y2+1]==color)
                            P.push(std::make_pair(x2-1,y2+1));
                        if(x2+1<wi && y2+1<h && MImagen[x2+1][y2+1]==color )
                            P.push(std::make_pair(x2+1,y2+1));

                    }


                }
                label+=20;
            }
        }
    }
    qDebug()<<(label-20)/20;//objetos encontrados
    for(int i=0;i<h;i++){
        QRgb *nVal =(QRgb*)imagen.scanLine(i);
        int qB=0;
        for(int j=0;j<wi;j++){
            if(MImagen[j][i]==0 || MImagen[j][i]==255)
                nVal[j]=qRgb(MImagen[j][i],MImagen[j][i],MImagen[j][i]);
            else
                nVal[j]=qRgb(MImagen[j][i]*2,MImagen[j][i]*3,MImagen[j][i]);
        }

    }

    pixmap.convertFromImage(imagen);

    img->setImage(pixmap);
    /**
    for(int i=0;i<wi;i++){
        for(int e=0;e<h;e++){
            std::cout<<MImagen[i][e];
        }
        std::cout<<endl;
    }**/



}



/**
 * @brief preCargaImagen
 * Alamcenamos todos los valores de lso pixeles de la imagen en una matriz cuadrada
 */


void labeling::preCargaImagen(){
    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();

    wi= pixm->width();
    h= pixm->height();

    for(int i=0;i<h;i++){
        for(int j=0;j<wi;j++){
            MImagen[j][i]=qGray(imagen.pixel(j,i));
        }
    }




}
