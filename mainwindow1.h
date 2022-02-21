#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <QStringListModel>

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

signals:
    void call_data_window();
    void call_rang_window();

private slots:
    void butt_data_clicked();
    void butt_rang_clicked();

private:
    Ui::MainWindow1 *ui;
};

#endif // MAINWINDOW1_H
