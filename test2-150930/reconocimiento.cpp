#include "reconocimiento.h"
#include "math.h"

reconocimiento::reconocimiento()
{
    A[0][0]=0.578126;
    A[0][1]=0.0167964;
    A[0][2]=1.07317e-05;
    A[0][3]=8.21167e-07;

    A[1][0]=0.241277;
    A[1][1]=0.000666358;
    A[1][2]=6.68981e-09;
    A[1][3]=1.69011e-09;

    A[2][0]=0.215919;
    A[2][1]=0.00071175;
    A[2][2]=5.58751e-07;
    A[2][3]=4.62673e-09;

    A[3][0]=0.307668;
    A[3][1]=0.00395238;
    A[3][2]=4.22851e-06;
    A[3][3]=1.31811e-07;

    A[4][0]=0.460491;
    A[4][1]=0.07051;
    A[4][2]=1.10422e-07;
    A[4][3]=7.334e-08;


    B[0][0]=0.320192;
    B[0][1]=0.0128076;
    B[0][2]=4.9913e-08;
    B[0][3]=4.87163e-08;

    B[1][0]=0.392212;
    B[1][1]=0.0793604;
    B[1][2]=1.21256e-08;
    B[1][3]=1.58598e-09;

    B[2][0]=0.266773;
    B[2][1]=0.0191707;
    B[2][2]=6.40032e-08;
    B[2][3]=4.11844e-08;

    B[3][0]=0.25522;
    B[3][1]=0.0284303;
    B[3][2]=3.406e-08;
    B[3][3]=1.53372e-08;

    B[4][0]=0.261777;
    B[4][1]=0.0024526;
    B[4][2]=2.69217e-08;
    B[4][3]=9.46561e-09;


}

void reconocimiento::setImagen(dlgImage *imagen){
    img=imagen;
}

void reconocimiento::doReconocimiento(){
    std::vector<double> M;//momentos

    objHu = new hu();
    objHu->setImagen(img);
    objHu->preCargaImagen();

    M=objHu->getHu();

    //qDebug()<<M[0]<<M[1]<<M[2]<<M[3];


    double d1;
    double d2;
    int letra=0;
    double min =99999999;
    for(int i =0;i<5;i++){
        d1 =sqrt(pow((A[i][0]-M[0]),2)+pow((A[i][1]-M[1]),2)+pow((A[i][2]-M[2]),2)+pow((A[i][3]-M[3]),2));
        d2 =sqrt(pow((B[i][0]-M[0]),2)+pow((B[i][1]-M[1]),2)+pow((B[i][2]-M[2]),2)+pow((B[i][4]-M[3]),2));
     if(min>d1){
         min =d1;
         letra =1;
     }
     if(min>d2){
         min = d2;
         letra=2;
     }
    }


       if(letra==2)
         qDebug()<<("La letra es B");
       else
          qDebug()<<("La letra es A");



}
