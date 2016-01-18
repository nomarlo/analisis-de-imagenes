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
    float Mask[256][256];
    int h,w,xp,yp;
    float R,G,B;
    int alpha,beta;
    int n; //para la media
    int cruz=ui->cruz->checkState();
    qDebug()<<cruz;
    x=ui->columna->text().toInt()-1;
    y=ui->fila->text().toInt()-1;
    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();
    int M[256];
    alpha=ui->alpha->currentIndex();
    beta=ui->beta->currentIndex();


    for(int i=0;i<t;i++){
        for(int e=0;e<t;e++){
           Mask[i][e]=model->index(i,e).data().toFloat();
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
            R=G=B=0.0;
            n=0;
            for(int a=0;a<t;a++){
                if(yp>=0&& yp<h ){
                    xp=aux;//regresa xp a su valor original
                   // qDebug()<<xp<<yp;
                    for(int b=0;b<t;b++){
                        if(xp>=0&& xp<w && (cruz==0 || (b==0 &&a==1) || (b==1 &&(a==0 || a==2) )|| (b==2 && a==1)  )){
                            if(alpha==0 || alpha==3){//suma || media
                                //beta== 0:multiplicacion, 1:suma, 2:resta
                                R+=(float)beta==0?(float)qRed(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ?(float) qRed(imagen.pixel(xp,yp))+Mask[a][b]:(float)qRed(imagen.pixel(xp,yp))-Mask[a][b] ;
                                G+=(float)beta==0?(float)qGreen(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ? (float)qGreen(imagen.pixel(xp,yp))+Mask[a][b]:(float)qGreen(imagen.pixel(xp,yp))-Mask[a][b] ;
                                B+=(float)beta==0?(float)qBlue(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ? (float)qBlue(imagen.pixel(xp,yp))+Mask[a][b]:(float)qBlue(imagen.pixel(xp,yp))-Mask[a][b] ;
                            }
                            else if(alpha==1){//maximo
                                R=(float)qMax(R,beta==0?(float)qRed(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ? (float)qRed(imagen.pixel(xp,yp))+Mask[a][b]:(float)qRed(imagen.pixel(xp,yp))-Mask[a][b]);
                                G=(float)qMax(G,beta==0?(float)qGreen(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ? (float)qGreen(imagen.pixel(xp,yp))+Mask[a][b]:(float)qGreen(imagen.pixel(xp,yp))-Mask[a][b]) ;
                                B=(float)qMax(B,beta==0?(float)qBlue(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ?(float) qBlue(imagen.pixel(xp,yp))+Mask[a][b]:(float)qBlue(imagen.pixel(xp,yp))-Mask[a][b]) ;
                            }
                            else if(alpha==2){//minimo
                                R=(float)qMin(R,beta==0?(float)qRed(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ?(float) qRed(imagen.pixel(xp,yp))+Mask[a][b]:(float)qRed(imagen.pixel(xp,yp))-Mask[a][b]);
                                G=(float)qMin(G,beta==0?(float)qGreen(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ? (float)qGreen(imagen.pixel(xp,yp))+Mask[a][b]:(float)qGreen(imagen.pixel(xp,yp))-Mask[a][b]) ;
                                B=(float)qMin(B,beta==0?(float)qBlue(imagen.pixel(xp,yp))*Mask[a][b]: beta==1 ? (float)qBlue(imagen.pixel(xp,yp))+Mask[a][b]:(float)qBlue(imagen.pixel(xp,yp))-Mask[a][b]) ;
                            }
                            n++;

                        }
                        xp++;
                    }
                }
                yp++;
            }
            /**para la media**/
            R=(float)alpha==3?R/n:R;
            G=(float)alpha==3?G/n:G;
            B=(float)alpha==3?B/n:B;

            /**
            R=R>255?255:R;
            G=G>255?255:G;
            B=B>255?255:B;
            R=R<0?0:R;
            G=G<0?0:G;
            B=B<0?0:B;
            **/
            nVal[j]=qRgb(R,G,B);

        }

    }

    pixmap.convertFromImage(imagen);

    img->setImage(pixmap);



}



