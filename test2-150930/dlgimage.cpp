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

void dlgImage::setFileName(QString file) {
    fileName=file;

    QPixmap pixmap;
    pixmap.load(fileName);

    ui->image->setPixmap(pixmap);

}

void dlgImage::saveAs(QString file) {
    fileName=file;

    const QPixmap *pixmap=ui->image->pixmap();

    pixmap->save(fileName);
}


