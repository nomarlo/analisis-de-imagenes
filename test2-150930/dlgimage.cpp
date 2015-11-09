#include "dlgimage.h"
#include "ui_dlgimage.h"

dlgImage::dlgImage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgImage)
{
    ui->setupUi(this);
}

dlgImage::~dlgImage()
{
    delete ui;
}

void dlgImage::setStatusBar(QStatusBar *sb) {
    ui->image->setStatusBar(sb);
}

QPixmap dlgImage::setFileName(QString file) {
    fileName=file;

    QPixmap pixmap;
    pixmap.load(fileName);

    ui->image->setPixmap(pixmap);

    return pixmap;

}

void dlgImage::setImage(QPixmap pixmap){
    ui->image->setPixmap(pixmap);

}



void dlgImage::saveAs(QString file) {
    fileName=file;

    const QPixmap *pixmap=ui->image->pixmap();

    pixmap->save(fileName);
}

const QPixmap* dlgImage::getPixmap(){

    return ui->image->pixmap();
}


