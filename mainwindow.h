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
#include "cards.h"

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
    QString main_player_name;
    QString ai_player1_name;
    QString ai_player2_name;
    static int main_player_id;
    static int ai_player1_id;
    static int ai_player2_id;
    static int init_x_value;
    static int init_y_value;
    static int pos_ai_player[2];
    static int current_postions[3];
    static int player_index;
    static int human_player_turns;
    explicit MainWindow(QWidget *parent = 0);
    int gen_rand_number(int max);
    ~MainWindow();
    QString name;

private slots:
    void on_move_clicked();
    void on_start_clicked();

    void on_card_holder_clicked();

    void on_draw_card_clicked();

    void on_play_card_clicked();

private:
    Ui::MainWindow *ui;
    QImage  *imageObject;
    QGraphicsScene *scene;
    void relocate(int place_id, QWidget *player, int y_offset);
    void prepare_board();
    void render_room_list(int place_id);
    int move_ai_player(QWidget *player, int current_pos, int y_offset);
    void set_cards_in_hand();
    void set_icon_as_card();
    void setup_tables();
};

#endif // MAINWINDOW_H
