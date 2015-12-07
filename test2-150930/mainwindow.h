#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include "dlgimage.h"
#include "histograma.h"
#include "convolucion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMdiArea  *mdiArea;
    dlgImage *img;
    histograma *hist;
    convolucion *conv;
private slots:
    void open();
    void saveAs();
    void rango();
    void setConvolucion();
};

#endif // MAINWINDOW_H
