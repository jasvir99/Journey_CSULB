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

//Done with initialization of static data members

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
     * Constructor for main window class
     */

    QPixmap* image = new QPixmap(":/images/resources/board.png");
    ui->setupUi(this);
    ui->mainImage->setPixmap(*image);
    this->setWindowTitle("Journey at CSULB");

    //Qtime implementation for generating random numbers
    QTime time = QTime::currentTime();
    qsrand((uint)time.second());

    //After generating random numbers, prepare board
    this->prepare_board();

    //render dropdown list for room number 14 which is initial player postion
    this->render_room_list(14);

    //hide dropdown and move button. They will be displayed once start button
    //is clicked
    ui->rooms->hide();
    ui->move->hide();
}

MainWindow::~MainWindow()
{
    /*
     * Destructor for main window class
     */

    delete ui;
}

int MainWindow::gen_rand_number(int max)
{
    /*
     * function to generate random number b/w 0 and max
     */

    int b = qrand() % max;
    return b;
}

void MainWindow::prepare_board()
{
    /*
     * This function prepare board and do preprocessing which includes:
     * -> select one of the player as human player
     * -> assign different color to human player
     */

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
    /*
     * Funtion to relocate player from one place to another.
     * This function accept argument:
     * -> place_id: id of place to which player is to be moved
     * -> *pointer: pointer pointing to player which is supposed to be moved
     * -> y_offset: a fixed offset iny direction so that players should not
     *              overlap each other
     */

    DataProcessing data;
    int x_value = data.get_xvalue(place_id);
    int y_value = data.get_yvalue(place_id);
    player->move(x_value,y_value + y_offset);
}

void MainWindow::on_move_clicked()
{
    /*
     * This function is a signal slot of move button which will called on
     * clicking move button. It will get current index of rooms list and get
     * associated user data which is id of that particular room/place. Using
     * that id, main player will be relocated and it followed by movement of
     * ai players using move_ai_player() function. When all of the three players
     * are done with movement, list of palces will be rendered again.
     */

    DataProcessing data;

    //get current index and fetch user data.
    int current_index = ui->rooms->currentIndex();
    int user_data = ui->rooms->itemData(current_index).toInt();

    //relocate main_player as per selected room
    this->relocate(user_data,main_player,0);

    ui->move_main_player->setText("Main player moved to " + QString::number(user_data));

    qDebug()<<pos_ai_player[0];
    qDebug()<<pos_ai_player[1];

    //move ai player to random available room
    int pos_ai_1 = this->move_ai_player(ai_player1,pos_ai_player[0], 18);

    ui->move_ai_1->setText("First AI player moved to " + \
                           QString::number(pos_ai_1));

    int pos_ai_2 = this->move_ai_player(ai_player2,pos_ai_player[1],36);

    ui->move_ai_2->setText("Second AI player moved to " + \
                           QString::number(pos_ai_2));

    //render the list of rooms
    this->render_room_list(user_data);
}

void MainWindow::render_room_list(int place_id)
{
    /*
     * This function simply render the new list of available rooms. It accepts
     * 'place_id' as argument which is used to get accessible rooms from
     * provided argument.
     */

    //clear current list
    ui->rooms->clear();

    DataProcessing data;

    //get accessible rooms
    QJsonArray accessibles = data.get_accessible(place_id);

    //get title of rooms and add them to list with
    int json_index;
    for(json_index = 0; json_index < accessibles.size(); json_index++)
    {
        int room_id = accessibles[json_index].toInt();
        QString title = data.get_title(room_id);
        ui->rooms->addItem(title, QVariant(room_id));
    }
}

void MainWindow::on_start_clicked()
{
    /*
     * This function is a signal slot for start button. On clicking start button,
     * player move to the initial position and hidden widgets(rooms and move)
     * will show up.
     */

    //move players to initial postion
    main_player->move(init_x_value,init_y_value);
    ai_player1->move(init_x_value,init_y_value-18);
    ai_player2->move(init_x_value,init_y_value-36);

    // hide start button and displaye move and rooms.
    ui->start->hide();
    ui->rooms->show();
    ui->move->show();
}

int MainWindow::move_ai_player(QWidget *player, int current_pos, int y_offset)
{
    /*
     * This function is used to move ai players. Function accepts following
     * arguments:
     * -> *player: pointer to ai player
     * -> current_pos: current position of *player
     * -> y_offset: fixed y_offset of *player
     */

    DataProcessing data;

    //get accessible rooms from current position. It will be a Json Array.
    QJsonArray accessibles = data.get_accessible(current_pos);

    //generate random index to get random number accessibles array.
    int random_index = this->gen_rand_number(accessibles.size());
    int random_place_id = accessibles[random_index].toInt();

    qDebug()<<"random"<<random_place_id;
    qDebug()<<"access"<<accessibles;

    //relocate player
    this->relocate(random_place_id,player, y_offset);

    //update current position of player
    pos_ai_player[player_index] = random_place_id;

    //since we have only two players, player index should be either 0 or 1. If
    // it is 1, it should be reset to 0.
    if(player_index == 1)
        player_index = 0;
    else
        player_index++;

    return random_place_id;
}
