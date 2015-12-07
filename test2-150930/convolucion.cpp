#include "convolucion.h"
#include "ui_convolucion.h"
#include <QStandardItemModel>
#include <QDebug>






convolucion::convolucion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::convolucion)
{
    ui->setupUi(this);
}

convolucion::~convolucion()
{
    delete ui;
}

void convolucion::setImagen(dlgImage *imagen){
    img=imagen;
}

void convolucion::  setGrid(){
    t=ui->tamano->text().toInt();

    model= new QStandardItemModel(t,t,this); //t Rows and t Columns
    for(int i=0;i<t;i++)
        model->setHorizontalHeaderItem(0, new QStandardItem(QString(i)));

    ui->tableView->setModel(model);

}

void convolucion::  doCon(){
    t=ui->tamano->text().toInt();
    int Mask[256][256];
    int h,w,xp,yp;
    int R,G,B;
    x=ui->columna->text().toInt();
    y=ui->fila->text().toInt();
    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();
    int M[256];


    for(int i=0;i<t;i++){
        for(int e=0;e<t;e++){
           Mask[i][e]=model->index(i,e).data().toInt();
        }
    }

    w= pixm->width();
    h= pixm->height();


    //qDebug()<<M[0];
    for(int i=0;i<h;i++){
        QRgb *nVal =(QRgb*)imagen.scanLine(i);
        for(int j=0;j<w;j++){
            xp=j-x;
            yp=i-y;
            int aux=xp;
            R=G=B=0;
            for(int a=0;a<t;a++){
                if(yp>=0&& yp<h){
                    xp=aux;

                    for(int b=0;b<t;b++){
                        if(xp>=0&& xp<w){
                            R+=qRed(imagen.pixel(xp,yp))*Mask[a][b];
                            G+=qGreen(imagen.pixel(xp,yp))*Mask[a][b];
                            B+=qBlue(imagen.pixel(xp,yp))*Mask[a][b];
                        }
                        xp++;
                    }
                }
                yp++;
            }
            R=R>255?255:R;
            G=G>255?255:G;
            B=B>255?255:B;
            nVal[j]=qRgb(R,G,B);
        }

    }

    pixmap.convertFromImage(imagen);

    img->setImage(pixmap);



}



