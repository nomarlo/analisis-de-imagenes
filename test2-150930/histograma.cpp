#include "histograma.h"
#include "ui_histograma.h"

histograma::histograma(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::histograma)
{
    ui->setupUi(this);
}

histograma::~histograma()
{
    delete ui;
}

void histograma::setDatos(QPixmap pixmap){
    QRgb pixel;
    int red, green,blue,gray;

    R =new QVector<double>(256);
    G =new QVector<double>(256);
    B =new QVector<double>(256);
    Gr =new QVector<double>(256);
    X= new QVector<double>(256);


    for (int i=0; i<256; ++i) X->operator [](i)=i;

    for(int x=0;x<pixmap.width();x++){
        for(int y=0;y<pixmap.height();y++){
            pixel=pixmap.toImage().pixel(x,y);

            red=qRed(pixel);
            green=qGreen(pixel);
            blue=qBlue(pixel);
            gray=(red * 11 + green * 16 + blue * 5)/32;

            R->operator [](red)++;
            G->operator [](green)++;
            B->operator [](blue)++;
            Gr->operator [](gray)++;

        }
    }

    Dibujar(ui->customPlot);

    ui->customPlot->replot();
}

void histograma::Dibujar(QCustomPlot *customPlot){
    // add two new graphs and set their look:
      customPlot->addGraph();
      customPlot->graph(0)->setPen(QPen(Qt::red)); // line color blue for first graph
      customPlot->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20))); // first graph will be filled with translucent blue


      // configure right and top axis to show ticks but no labels:
      // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
      customPlot->xAxis2->setVisible(true);
      customPlot->xAxis2->setTickLabels(false);
      customPlot->yAxis2->setVisible(true);
      customPlot->yAxis2->setTickLabels(false);
      // make left and bottom axes always transfer their ranges to right and top axes:
      connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
      connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
      // pass data points to graphs:
      customPlot->graph(0)->setData(*X, *R);
      // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
      customPlot->graph(0)->rescaleAxes();

      customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void histograma::ReDibujar(){
    int i=0;
    if(ui->red->isChecked()){
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setPen(QPen(Qt::red)); // line color blue for first graph
        ui->customPlot->graph(i)->setBrush(QBrush(QColor(255, 0, 0, 20))); // first graph will be filled with translucent blue
        ui->customPlot->graph(i)->setData(*X, *R);
        i++;
     }

    if(ui->green->isChecked()){
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setPen(QPen(Qt::green)); // line color blue for first graph
        ui->customPlot->graph(i)->setBrush(QBrush(QColor(0, 255, 0, 20))); // first graph will be filled with translucent blue
        ui->customPlot->graph(i)->setData(*X, *G);
        i++;
     }

    if(ui->blue->isChecked()){
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setPen(QPen(Qt::blue)); // line color blue for first graph
        ui->customPlot->graph(i)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
        ui->customPlot->graph(i)->setData(*X, *B);
        i++;
     }

    if(ui->gray->isChecked()){
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setPen(QPen(Qt::black)); // line color blue for first graph
        ui->customPlot->graph(i)->setBrush(QBrush(QColor(0, 0, 0, 20))); // first graph will be filled with translucent blue
        ui->customPlot->graph(i)->setData(*X, *Gr);
        i++;
     }




      ui->customPlot->xAxis2->setVisible(true);
      ui->customPlot->xAxis2->setTickLabels(false);
      ui->customPlot->yAxis2->setVisible(true);
      ui->customPlot->yAxis2->setTickLabels(false);
      connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
      connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

      ui->customPlot->graph(0)->rescaleAxes();
      ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

      ui->customPlot->replot();


}
