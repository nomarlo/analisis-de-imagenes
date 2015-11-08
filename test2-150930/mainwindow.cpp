#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgimage.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open() {

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));

    dlgImage *img;
    img=new dlgImage(mdiArea);
    img->setFileName(fileName);
    img->setStatusBar(ui->statusBar);

    mdiArea->addSubWindow(img);
    img->show();


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










