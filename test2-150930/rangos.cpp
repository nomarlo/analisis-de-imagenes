#include "rangos.h"
#include "ui_rangos.h"

rangos::rangos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rangos)
{
    ui->setupUi(this);
}

rangos::~rangos()
{
    delete ui;
}

void rangos::setImagen(dlgImage *imagen, histograma *histo){
    hist=histo;
    img=imagen;
}


void rangos::setRangos(){
    int h,w,min,max;
    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();
    int M[256];
    min=ui->xmax->text().toInt();
    max=ui->xmin->text().toInt();

    w= pixm->width();
    h= pixm->height();

    for(int i=0;i<256;i++){
        if(i<min)
            M[i]=0;
        else if(i>max)
            M[i]=255;
        else{
            M[i]=(255/(max-min))*(i-min);

        }
    }

    //qDebug()<<M[0];
    for(int i=0;i<h;i++){
        QRgb *nVal =(QRgb*)imagen.scanLine(i);
        for(int j=0;j<w;j++){
            nVal[j]=qRgb(M[qRed(imagen.pixel(j,i))],M[qGreen(imagen.pixel(j,i))],M[qBlue(imagen.pixel(j,i))]);
        }

    }

    pixmap.convertFromImage(imagen);

    img->setImage(pixmap);
    hist->setDatos(pixmap);


}
