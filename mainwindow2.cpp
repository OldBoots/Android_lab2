#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QVector <table_data> data;
    table_data td;
    model = new QStandardItemModel;
    QStandardItem * i_name;
    QStandardItem * i_group;
    QStandardItem * i_rang;
    QStandardItem * i_ico;
    QStandardItem * i_header;
    QStringList l_group;
    QStringList l_name_f;
    QStringList l_name_s;
    QStringList l_header;
    l_group << "Монолит" << "Одиночки" << "Долг" << "Свобода" << "Военные" << "Ученые" << "Чистое Небо" << "Наемники" << "Бандиты" << "Ренегаты"  << "Зомбированные" << "Грех";
    l_header << "Нашивка" << "Имя" << "Группировка" << "Ранг";
    l_name_f << "Бараш" << "Фракиец" << "Корсак" << "Конфуций" << "Фонарщик" << "Дворф" << "Вяз" << "Эрагон" << "Яник" << "Костяк" << "Бадяга" << "Пифон" << "Песец" << "Стэн" << "Лапоть" << "Гиродон" << "Ред" << "Камердинер" << "Критик" << "Инструктор" << "Нортон" << "Феликс";
    l_name_s << "Лютый" << "Кривой" << "Убойный" << "Тупой" << "Шустрый" << "Темный" << "Любопытный" << "Симпотный" << "Томный" << "Ровный" << "Сильный" << "Красный" << "Мирный" << "Эфирный";
    int index_group, n_rec = 30;
    for(int i = 0; i < n_rec; i++){
        td.name = l_name_f[Rand(0,l_name_f.size() - 1)] + " " + l_name_s[Rand(0,l_name_s.size() - 1)];
        index_group = Rand(0,l_group.size() - 1);
        td.ico = QBrush(QPixmap(":/" + QString::number(index_group + 1) + ".png").scaled(64,26, Qt::IgnoreAspectRatio));
        td.group = l_group[index_group];
//        td.rang = QString::number(Rand(150, 2500));
        td.rang = Rand(150, 2500);
        data << td;
    }

    QFont f_table("Segoe UI", 9);
    model->setColumnCount(4);
    for(int i = 0; i < 4; i++){
        i_header = new QStandardItem;
        i_header->setText(l_header[i]);
        i_header->setFont(f_table);
        model->setHorizontalHeaderItem(i,i_header);
    }


    for(int i = 0; i < n_rec; i++){
        i_ico = new QStandardItem;
        i_ico->setBackground(data[i].ico);
        model->setItem(i, 0, i_ico);

        i_name = new QStandardItem;
        i_name->setText(data[i].name);
        i_name->setFont(f_table);
        model->setItem(i, 1, i_name);

        i_group = new QStandardItem;
        i_group->setText(data[i].group);
        i_group->setFont(f_table);
        model->setItem(i, 2, i_group);

        i_rang = new QStandardItem;
        i_rang->setData(data[i].rang, 0);
        i_rang->setFont(f_table);
        i_rang->setTextAlignment(Qt::AlignCenter);
        model->setItem(i, 3, i_rang);
        ui->tableView->setRowHeight(i, 32);
    }
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 64);
    ui->tableView->setColumnWidth(1, 105);
    ui->tableView->setColumnWidth(2, 80);
    ui->tableView->setSortingEnabled(true);
    QScroller::grabGesture(ui->tableView, QScroller::LeftMouseButtonGesture);
    ui->tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableView->grabGesture(Qt::SwipeGesture);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->but_group, SIGNAL(clicked()), this, SLOT(butt_group_clicked()));
    connect(ui->butt_data, SIGNAL(clicked()), this, SLOT(butt_data_clicked()));
}

void MainWindow2::butt_data_clicked(){
    emit call_data_window();
    this->hide();
}

void MainWindow2::butt_group_clicked(){
    emit call_group_window();
    this->hide();
}

int Rand(int min, int max){
    if (min == max){
        return min;
    }
    std::uniform_int_distribution dist(min, max);
    return dist(*QRandomGenerator::global());
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
