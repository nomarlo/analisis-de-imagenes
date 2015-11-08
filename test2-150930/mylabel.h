#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QStatusBar>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);
    void setStatusBar(QStatusBar *sb);


private:
    void mouseMoveEvent(QMouseEvent * event);
    QStatusBar *statusBar;

signals:

public slots:
};

#endif // MYLABEL_H
