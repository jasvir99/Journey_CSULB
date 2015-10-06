#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString name;

private:
    Ui::MainWindow *ui;
    QImage  *imageObject;
    QGraphicsScene *scene;
    void show_image();
};

#endif // MAINWINDOW_H
