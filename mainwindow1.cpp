#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);

    QStringList list;
    list << "Монолит" << "Одиночки" << "Долг" << "Свобода" << "Военные" << "Ученые" << "Чистое Небо" << "Наемники" << "Бандиты" << "Ренегаты"  << "Зомбированные" << "Грех";
    QStringListModel *model = new QStringListModel;
    model->setStringList(list);
    ui->listView->setModel(model);

    connect(ui->butt_data, SIGNAL(clicked()), this, SLOT(butt_data_clicked()));
    connect(ui->butt_rang, SIGNAL(clicked()), this, SLOT(butt_rang_clicked()));
}

void MainWindow1::butt_data_clicked(){
    emit call_data_window();
    this->hide();
}

void MainWindow1::butt_rang_clicked(){
    emit call_rang_window();
    this->hide();
}

MainWindow1::~MainWindow1()
{
    delete ui;
}
