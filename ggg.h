#ifndef GGG_H
#define GGG_H

#include <QMainWindow>

namespace Ui {
class ggg;
}

class ggg : public QMainWindow
{
    Q_OBJECT

public:
    explicit ggg(QWidget *parent = nullptr);
    ~ggg();

private:
    Ui::ggg *ui;
};

#endif // GGG_H
