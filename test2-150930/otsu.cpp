#include "otsu.h"
#include "ui_otsu.h"
#include "math.h"
Otsu::Otsu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Otsu)
{
    ui->setupUi(this);
}

Otsu::~Otsu()
{
    delete ui;
}

void Otsu::setImagen(dlgImage *imagen, histograma *histo){
    hist=histo;
    img=imagen;
    Acumulado =new QVector<double>();
    Acumulado2 =new QVector<double>();
}

void Otsu::doOtsu(){
    //qDebug()<<Acumulado->operator [](5);
    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();
    int wi,h; //width y height de las imagenes

    wi= pixm->width();
    h= pixm->height();

    double varianza=0;
    int t=0;
    double w,m,w2,m2;
    double d1,d2,d3;//divisores

    doAcumulado();
    qDebug()<<"m"<<Acumulado->operator [](0);
    for(int i=0;i<256;i++){
        d1=(double)Acumulado->operator [](255);
        d2=(double)Acumulado->operator [](i);
        d3=d1-d2;
        w=( ((double)Acumulado->operator [](i) ) /d1) ;
        w2= (1-w);
        m= ( (double)Acumulado2->operator [](i)/d2  );
        m2= (( (double)Acumulado2->operator [](255)-(double)Acumulado2->operator [](i))/d3 );

        qDebug()<<w<<w2<<m<<m2;
        w*=w2;
        m-=m2;
        m=pow(m,2);
        if(w*m>=varianza){
            varianza=w*m;
            t=i;
        }
        qDebug()<<w*m;
    }

    for(int i=0;i<h;i++){
        QRgb *nVal =(QRgb*)imagen.scanLine(i);
        int qG=0;
        for(int j=0;j<wi;j++){
            qG=qGray(imagen.pixel(j,i))>t?255:0;
            nVal[j]=qRgb(qG,qG,qG);
        }

    }

    qDebug()<<t;

    pixmap.convertFromImage(imagen);

    img->setImage(pixmap);
    hist->setDatos(pixmap);
}

void Otsu::doAcumulado(){
    Acumulado->push_back((double)hist->Gr->operator [](0));
    for(int i=1;i<256;i++){
        Acumulado->push_back((double)hist->Gr->operator [](i)+(double)Acumulado->operator [](i-1));
    }

    Acumulado2->push_back(0);
    for(int i=1;i<256;i++){
        Acumulado2->push_back( (double)(hist->Gr->operator [](i)*i)+(double)Acumulado2->operator [](i-1));
    }

}
