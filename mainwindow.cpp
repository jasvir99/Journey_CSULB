/**
 *
 *       \file       mainwindow.cpp
 *
 *       \brief      Include functions rendering of mainwindow and
 *                   movement of player.
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"

//Initializing static data members

QWidget* MainWindow::main_player = 0;
QWidget* MainWindow::ai_player1 = 0;
QWidget* MainWindow::ai_player2 = 0;

int MainWindow::init_x_value = 812;
int MainWindow::init_y_value = 1100;
int MainWindow::player_index = 0;

int MainWindow::pos_ai_player[2] = {14,14};
//Done with initialization of data members

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap* image = new QPixmap(":/images/resources/board.png");
    //QPixmap* card = new QPixmap(":/images/resources/card1.png"); pointer to cards
    ui->setupUi(this);
    ui->mainImage->setPixmap(*image);
    //ui->cards->setPixmap(*card); adds card into ui
    this->setWindowTitle("Journey at CSULB");
    QTime time = QTime::currentTime();
    qsrand((uint)time.second());
    this->prepare_board();
    this->render_room_list(14);
    ui->rooms->hide();
    ui->move->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::gen_rand_number(int max)
{
    int b = qrand() % max;
    return b;
}

void MainWindow::prepare_board()
{
    players.append(ui->player1);
    players.append(ui->player2);
    players.append(ui->player3);
    int a = this->gen_rand_number(3);
    main_player = players[a];
    main_player->setStyleSheet("color: red;");
    players.removeAt(a);
    ai_player1 = players[0];
    ai_player2 = players[1];
    ai_player1->setStyleSheet("color: orange");
    ai_player2->setStyleSheet("color: orange");
}

void MainWindow::relocate(int place_id, QWidget *player, int y_offset)
{
    DataProcessing data;
    int x_value = data.get_xvalue(place_id);
    int y_value = data.get_yvalue(place_id);
    player->move(x_value,y_value + y_offset);
}

void MainWindow::on_move_clicked()
{
    DataProcessing data;
    //QString place = "0";
    //data.get_title(0);
    //this->relocate(ui->player1);
    //slot to move player.
    int current_index = ui->rooms->currentIndex();
    int user_data = ui->rooms->itemData(current_index).toInt();
    this->relocate(user_data,main_player,0);
    qDebug()<<pos_ai_player[0];
    qDebug()<<pos_ai_player[1];
    this->move_ai_player(ai_player1,pos_ai_player[0], 18);
    this->move_ai_player(ai_player2,pos_ai_player[1],36);
    this->render_room_list(user_data);
}

void MainWindow::render_room_list(int room)
{
    ui->rooms->clear();
    DataProcessing data;
    QJsonArray accessibles = data.get_accessible(room);
    int json_index;
    for(json_index = 0; json_index < accessibles.size(); json_index++)
    {
        int accessible_id = accessibles[json_index].toInt();
        QString title = data.get_title(accessible_id);
        ui->rooms->addItem(title, QVariant(accessible_id));
    }
}

void MainWindow::on_start_clicked()
{
    main_player->move(init_x_value,init_y_value);
    ai_player1->move(init_x_value,init_y_value-18);
    ai_player2->move(init_x_value,init_y_value-36);
    ui->start->hide();
    ui->rooms->show();
    ui->move->show();
}

void MainWindow::move_ai_player(QWidget *player, int current_pos, int y_offset)
{
    DataProcessing data;
    QJsonArray accessibles = data.get_accessible(current_pos);
    int random_index = this->gen_rand_number(accessibles.size());
    int random_place_id = accessibles[random_index].toInt();
    qDebug()<<"random"<<random_place_id;
    qDebug()<<"access"<<accessibles;
    this->relocate(random_place_id,player, y_offset);
    pos_ai_player[player_index] = random_place_id;
    if(player_index == 1)
        player_index = 0;
    else
        player_index++;
}
