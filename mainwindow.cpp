#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/image.jpg").scaled(330,240,Qt::KeepAspectRatio));
    ui->label->setAlignment(Qt::AlignCenter);

    form_group = new MainWindow1;
    form_rang = new MainWindow2;
    connect(ui->butt_group, SIGNAL(clicked()), this, SLOT(butt_group_clicked()));
    connect(ui->butt_rang, SIGNAL(clicked()), this, SLOT(butt_rang_clicked()));

    connect(form_group, SIGNAL(call_data_window()), this, SLOT(showMaximized()));
    connect(form_group, SIGNAL(call_rang_window()), this, SLOT(show_rang_window()));

    connect(form_rang, SIGNAL(call_data_window()), this, SLOT(showMaximized()));
    connect(form_rang, SIGNAL(call_group_window()), this, SLOT(show_group_window()));

    QPalette darkPalette;                                                           // Настраиваем палитру для цветовых ролей элементов интерфейса
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
}

void MainWindow::butt_rang_clicked(){
    form_rang->showMaximized();
    this->hide();
}

void MainWindow::butt_group_clicked(){
    form_group->showMaximized();
    this->hide();
}

void MainWindow::show_group_window(){
    form_group->showMaximized();
}

void MainWindow::show_rang_window(){
    form_rang->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

