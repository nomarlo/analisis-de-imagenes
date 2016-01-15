#ifndef DISTANCE_H
#define DISTANCE_H

#include <QWidget>

namespace Ui {
class distance;
}

class distance : public QWidget
{
    Q_OBJECT

public:
    explicit distance(QWidget *parent = 0);
    ~distance();

private:
    Ui::distance *ui;
};

#endif // DISTANCE_H
