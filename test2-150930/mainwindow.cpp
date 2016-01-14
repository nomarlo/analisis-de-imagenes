#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgimage.h"
#include "histograma.h"
#include "rangos.h"
#include <QFileDialog>
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mdiArea=new QMdiArea(this);
    setCentralWidget(mdiArea);

    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(open()));
    connect(ui->actionSave_As,SIGNAL(triggered(bool)),this,SLOT(saveAs()));
    connect(ui->actionRangos,SIGNAL(triggered(bool)),this,SLOT(rango()));
    connect(ui->actionConvolucion,SIGNAL(triggered(bool)),this,SLOT(setConvolucion()));
    connect(ui->actionOperaciones,SIGNAL(triggered(bool)),this,SLOT(setOperaciones()));
    connect(ui->actionOtsu,SIGNAL(triggered(bool)),this,SLOT(setOtsu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open() {

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));




    img=new dlgImage(mdiArea);
    hist=new histograma(mdiArea);
   // pixmap->operator =(img->setFileName(fileName));
    hist->setDatos(img->setFileName(fileName));
    img->setStatusBar(ui->statusBar);


    mdiArea->addSubWindow(img);
    mdiArea->addSubWindow(hist);

    img->show();
    hist->show();



}



void MainWindow::saveAs() {
    const QMdiSubWindow *current_window=mdiArea->activeSubWindow();
    if (current_window!=0) {
        dlgImage *img=(dlgImage*)current_window->widget();

        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/",tr("Images (*.png *.bmp *.jpg)"));

        img->saveAs(fileName);

        ui->statusBar->showMessage(fileName);
    }
    else
        ui->statusBar->showMessage("No window selected");
}

void MainWindow::rango(){
    rangos *ran;
    ran =new rangos(mdiArea);

    ran->setImagen(img,hist);

    mdiArea->addSubWindow(ran);

    ran->show();
}

void MainWindow::setConvolucion(){

    conv =new convolucion (mdiArea);
    conv->setImagen(img);
    conv->setGrid();

    mdiArea->addSubWindow(conv);

    conv->show();
}


void MainWindow::setOperaciones(){

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    img2=new dlgImage(mdiArea);
    img2->setFileName(fileName);
    img2->setStatusBar(ui->statusBar);

    /**
    const QPixmap *pixm=img->getPixmap();
    const QPixmap *pixm2=img2->getPixmap();
    **/
    //qDebug()<<pixm->height()<<":"<<pixm2->height();
    oper =new operaciones (mdiArea);
    oper->setImagenes(img,img2);

    mdiArea->addSubWindow(oper);
    mdiArea->addSubWindow(img2);

    img2->show();
    oper->show();
}

void MainWindow::setOtsu(){

    otsuu =new Otsu (mdiArea);
    otsuu->setImagen(img, hist);
    //otsuu->doOtsu();

    mdiArea->addSubWindow(otsuu);

    otsuu->show();
}







