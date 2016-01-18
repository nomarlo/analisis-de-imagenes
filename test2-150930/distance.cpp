#include "distance.h"
#include "ui_distance.h"

distance::distance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::distance)
{
    ui->setupUi(this);
}

distance::~distance()
{
    delete ui;
}

void distance::setImagen(dlgImage *imagen){
    img=imagen;
}

void distance::doTransformacion(){

    QPixmap pixmap;
    const QPixmap *pixm=img->getPixmap();
    QImage imagen=pixm->toImage();
    int aux, aux2,aux3,aux4;

    color=0;
    vecindad=ui->geometria->currentIndex()==1?8:4;

    preCargaImagen();

    for(int x=0;x<wi;x++){
        for(int y=0;y<h;y++){
            if(MImagen[x][y]!=color){
                aux=aux2=aux3=aux4=999;
                //izquierda/arriba
                if(x-1>=0)
                    aux=MImagen[x-1][y]+1;
                if(y-1>=0)
                    aux2=MImagen[x][y-1]+1;
                if (vecindad==8){
                    if(x-1>=0 && y-1>=0 )
                        aux3=MImagen[x-1][y-1]+1;
                    if(x+1<=wi && y-1>=0 )
                        aux4=MImagen[x+1][y-1]+1;

                }

                MImagen[x][y]=qMin(MImagen[x][y],qMin(aux,qMin(aux2,qMin(aux3,aux4))));

            }
        }
    }

    for(int x=wi-1;x>=0;x--){
        for(int y=h-1;y>=0;y--){
            if(MImagen[x][y]!=color){
                aux=aux2=aux3=aux4=999;
                //derecha/abajo
                if(x+1<wi)
                   aux=MImagen[x+1][y]+1;
                if(y+1<h)
                   aux2=MImagen[x][y+1]+1;
                if (vecindad==8){
                    if(x-1<=0 && y+1<h )
                        aux3=MImagen[x-1][y+1]+1;
                    if(x+1<wi && y+1<h )
                        aux4=MImagen[x+1][y+1]+1;

                }

                MImagen[x][y]=qMin(MImagen[x][y],qMin(aux,qMin(aux2,qMin(aux3,aux4))));

            }
        }
    }





    for(int i=0;i<h;i++){
        QRgb *nVal =(QRgb*)imagen.scanLine(i);

        for(int j=0;j<wi;j++){

                nVal[j]=qRgb(MImagen[j][i],MImagen[j][i],MImagen[j][i]);

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


void distance::preCargaImagen(){
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
