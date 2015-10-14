#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "QtGui"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QList<QWidget*> players;
    static QWidget* main_player;
    static QWidget* ai_player1;
    static QWidget* ai_player2;
    static int init_x_value;
    static int init_y_value;
    static int pos_ai_player[2];
    static int player_index;
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
    void relocate(int place_id, QWidget *player, int y_offset);
    void prepare_board();
    int gen_rand_number(int max);
    void render_room_list(int room);
    void move_ai_player(QWidget *player, int current_pos, int y_offset);
};

#endif // MAINWINDOW_H
