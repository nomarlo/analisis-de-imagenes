#include "convolucion.h"
#include "ui_convolucion.h"

convolucion::convolucion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::convolucion)
{
    ui->setupUi(this);
}

convolucion::~convolucion()
{
    delete ui;
}
