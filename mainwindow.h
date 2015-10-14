#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "QtGui"

int const Max_Array = 3;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QList<QWidget*> players;
    int *ptr[Max_Array];
    static QWidget* main_player;
    static QWidget* ai_player1;
    static QWidget* ai_player2;
    static int init_x_value;
    static int init_y_value;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString name;

private slots:
    void on_move_clicked();
    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    QImage  *imageObject;
    QGraphicsScene *scene;
    void relocate(int x, int y);
    void prepare_board();
    int gen_rand_number();
    void render_room_list(int room);
};

#endif // MAINWINDOW_H
