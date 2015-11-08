#ifndef DLGIMAGE_H
#define DLGIMAGE_H

#include <QDialog>
#include <QStatusBar>

namespace Ui {
class dlgImage;
}

class dlgImage : public QDialog
{
    Q_OBJECT

public:
    explicit dlgImage(QWidget *parent = 0);
    ~dlgImage();
    QPixmap setFileName(QString file);
    void saveAs(QString file);
    void setStatusBar(QStatusBar *sb);

private:
    Ui::dlgImage *ui;
    QString fileName;
};

#endif // DLGIMAGE_H
