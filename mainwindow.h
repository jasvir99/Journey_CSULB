/**
 *
 *       \file       mainwindow.h
 *
 *       \brief      Header file for mainwindow.cpp which include functions
 *                   rendering of mainwindow and movement of player.
 *
 *       \version    0.1
 *       \date       Wedenesday, October 14 2015 11:58 PT\n
 *       Compiler    g++
 *
 *       \author     Jasvir Singh Grewal, jasvirsinghgrewal1991@gmail.com\n
 *                   Mayank Kasturia, mayankkasturia1993@gmail.com
 *
 *       License     GNU General Public License
 *
 *       \source     https://github.com/jasvir99/Journey_CSULB
 */

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
    void render_room_list(int place_id);
    int move_ai_player(QWidget *player, int current_pos, int y_offset);
};

#endif // MAINWINDOW_H
