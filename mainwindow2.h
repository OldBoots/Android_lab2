#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QStandardItemModel>
#include <QScroller>
#include <QScrollBar>

namespace Ui {
class MainWindow2;
}

struct table_data{
    QBrush ico;
    QString name;
    QString group;
    int rang;
};

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

signals:
    void call_group_window();
    void call_data_window();

private slots:
    void butt_group_clicked();
    void butt_data_clicked();

private:
    QStandardItemModel *model;
    Ui::MainWindow2 *ui;
};

int Rand(int min, int max);

#endif // MAINWINDOW2_H
