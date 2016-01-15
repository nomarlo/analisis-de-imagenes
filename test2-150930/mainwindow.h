#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include "dlgimage.h"
#include "histograma.h"
#include "convolucion.h"
#include "operaciones.h"
#include "otsu.h"
#include "labeling.h"
#include "distance.h"
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
    dlgImage *img2;//para utilizarla en las operaciones con dos imagenes
    histograma *hist;
    convolucion *conv;
    operaciones *oper;
    Otsu *otsuu;
    labeling *lab;
    distance *trans;

private slots:
    void open();
    void saveAs();
    void rango();
    void setConvolucion();
    void setOperaciones();
    void setOtsu();
    void setLabeling();
    void setTransformacion();
};

#endif // MAINWINDOW_H
