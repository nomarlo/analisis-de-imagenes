#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include "dlgimage.h"
#include "histograma.h"

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
private slots:
    void open();
    void saveAs();
    void rango();
};

#endif // MAINWINDOW_H
