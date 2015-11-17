#ifndef CONVOLUCION_H
#define CONVOLUCION_H

#include <QWidget>

namespace Ui {
class convolucion;
}

class convolucion : public QWidget
{
    Q_OBJECT

public:
    explicit convolucion(QWidget *parent = 0);
    ~convolucion();

private:
    Ui::convolucion *ui;
};

#endif // CONVOLUCION_H
