#include "operaciones.h"
#include "ui_operaciones.h"

operaciones::operaciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::operaciones)
{
    ui->setupUi(this);
}

operaciones::~operaciones()
{
    delete ui;
}
