#include "ggg.h"
#include "ui_ggg.h"

ggg::ggg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ggg)
{
    ui->setupUi(this);
}

ggg::~ggg()
{
    delete ui;
}
