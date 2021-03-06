#include "mylabel.h"
#include <QMouseEvent>




myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

    statusBar=0;
}

void myLabel::setStatusBar(QStatusBar *sb) {
    statusBar=sb;
}

void myLabel::mouseMoveEvent(QMouseEvent *event) {
    int x=event->x();
    int y=event->y();

    QRgb pixel=pixmap()->toImage().pixel(x,y);

    int red=qRed(pixel);
    int green=qGreen(pixel);
    int blue=qBlue(pixel);


    QString text;

    text.sprintf("X=%d, Y=%d R=%d G=%d B=%d ",x,y,red,green,blue);

    
    statusBar->showMessage(text);
}

