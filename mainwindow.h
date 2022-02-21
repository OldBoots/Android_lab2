#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow1.h"
#include "mainwindow2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void butt_group_clicked();
    void butt_rang_clicked();
    void show_group_window();
    void show_rang_window();

private:
    Ui::MainWindow *ui;
    MainWindow1 *form_group;
    MainWindow2 *form_rang;
};
#endif // MAINWINDOW_H
