#include "operaciones.h"
#include "ui_operaciones.h"
#include <QDebug>

operaciones::operaciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::operaciones)
{
    ui->setupUi(this);
}

operaciones::~operaciones()
{
    delete ui;
}

void operaciones::setImagenes(dlgImage *imagen, dlgImage *imagen2){
    img=imagen;
    img2=imagen2;
    const QPixmap *pixm=img->getPixmap();
    const QPixmap *pixm2=img2->getPixmap();

    qDebug()<<pixm->height()<<":"<<pixm2->height();
}

void operaciones::  doOp(){
    int op=ui->operaciones_2->currentIndex();
    int w,h,w2,h2; //width y height de las imagenes
    float R,G,B;

    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();
    const QPixmap *pixm2=img2->getPixmap();
    QImage imagen2=pixm2->toImage();

    w= pixm->width();
    h= pixm->height();
    w2= pixm2->width();
    h2= pixm2->height();
    //int p=990;
    //qDebug()<<imagen.height()<<":"<<imagen2.height();
    if(w==w2 && h==h2){
        switch(op){// 0 suma, 1 resta, 2 maximo, 3 minimo, 4 reflejado,  5 complemento
            case 0: case 1: case 2: case 3:
            for(int i=0;i<h;i++){
                    QRgb *nVal =(QRgb*)imagen.scanLine(i);
                    for(int j=0;j<w;j++){

                        R=op==0?qRed(imagen.pixel(j,i))+qRed(imagen2.pixel(j,i)): op==1? qRed(imagen.pixel(j,i))-qRed(imagen2.pixel(j,i)):op==2?qMax(qRed(imagen.pixel(j,i)),qRed(imagen2.pixel(j,i))):qMin(qRed(imagen.pixel(j,i)),qRed(imagen2.pixel(j,i)));
                        G=op==0?qGreen(imagen.pixel(j,i))+qGreen(imagen2.pixel(j,i)): op==1? qGreen(imagen.pixel(j,i))-qGreen(imagen2.pixel(j,i)):op==2?qMax(qGreen(imagen.pixel(j,i)),qGreen(imagen2.pixel(j,i))):qMin(qGreen(imagen.pixel(j,i)),qGreen(imagen2.pixel(j,i)));
                        B=op==0?qBlue(imagen.pixel(j,i))+qBlue(imagen2.pixel(j,i)): op==1? qBlue(imagen.pixel(j,i))-qBlue(imagen2.pixel(j,i)):op==2?qMax(qBlue(imagen.pixel(j,i)),qBlue(imagen2.pixel(j,i))):qMin(qBlue(imagen.pixel(j,i)),qBlue(imagen2.pixel(j,i)));
                       // R=R>255?255:R;G=G>255?255:G;R=B>255?255:B;
                        //R=R<0?0:R;G=G<0?0:G;B=B<0?0:B;
                        //qDebug()<<R<<":"<<qRed(imagen.pixel(j,i))<<":"<<qRed(imagen2.pixel(j,i));
                        nVal[j]=qRgb(R,G,B);


                    }

                }


            break;

            case 4:
                for(int i=0,e=h-1;i<h/2;i++,e--){
                    QRgb *nVal =(QRgb*)imagen.scanLine(i);
                    QRgb *nVal2 =(QRgb*)imagen.scanLine(e);
                    for(int j=0,k=w-1;j<w;j++,k--){
                        R=qRed(imagen.pixel(j,i));
                        G=qGreen(imagen.pixel(j,i));
                        B=qBlue(imagen.pixel(j,i));
                        nVal[j]=qRgb(qRed(imagen.pixel(k,e)),qGreen(imagen.pixel(k,e)),qBlue(imagen.pixel(k,e)));
                        nVal2[k]=qRgb(R,G,B);
                    }
                }

            break;

            case 5:

            for(int i=0;i<h;i++){
                    QRgb *nVal =(QRgb*)imagen.scanLine(i);
                    for(int j=0;j<w;j++){

                        nVal[j]=qRgb(255-qRed(imagen.pixel(j,i)),255-qGreen(imagen.pixel(j,i)),255-qBlue(imagen.pixel(j,i)));

                    }

                }

            break;





        }

        pixmap.convertFromImage(imagen);

        img->setImage(pixmap);

    }
    else{
        qDebug()<<"imagenes de diferentes dimensiones";
    }




}
