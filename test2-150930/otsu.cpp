#include "otsu.h"
#include "ui_otsu.h"

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
}

void Otsu::doOtsu(){
    qDebug()<<hist->Gr->operator [](45);
}
