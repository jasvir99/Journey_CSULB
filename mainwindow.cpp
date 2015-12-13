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
#include <iterator>
#include <algorithm>

//Initializing static data members

QWidget* MainWindow::main_player = 0;
QWidget* MainWindow::ai_player1 = 0;
QWidget* MainWindow::ai_player2 = 0;

int MainWindow::init_x_value = 1000;
int MainWindow::init_y_value = 1560;
int MainWindow::player_index = 0;
int MainWindow::human_player_turns = 1;
int MainWindow::pos_ai_player[2] = {17,17};

//Done with initialization of static data members

using namespace std;

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

    //render dropdown list for room number 17 which is initial player postion
    this->render_room_list(17);

    //hide dropdown and move button. They will be displayed once start button
    //is clicked
    ui->room_list->hide();
    ui->move->hide();
    ui->play_card->hide();
    ui->draw_card->hide();
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
    if(a == 0)
    {
        main_player_name = ui->player1->text();
        ai_player1_name = ui->player2->text();
        ai_player2_name = ui->player3->text();
    }

    else if(a == 1)
    {
        main_player_name = ui->player2->text();
        ai_player1_name = ui->player1->text();
        ai_player2_name = ui->player3->text();
    }

    else
    {
        main_player_name = ui->player3->text();
        ai_player1_name = ui->player1->text();
        ai_player2_name = ui->player2->text();
    }
    main_player->setStyleSheet("color: red;");
    players.removeAt(a);
    ai_player1 = players[0];
    ai_player2 = players[1];
    ai_player1->setStyleSheet("color: orange");
    ai_player2->setStyleSheet("color: orange");
    set_cards_in_hand();
    set_icon_as_card();
}

void MainWindow::setup_tables()
{
    QFont bold_font;
    bold_font.setBold(true);
    bold_font.setPointSize(10);

    ui->ip->setColumnCount(6);
    ui->ip->setRowCount(4);
    ui->ip->verticalHeader()->setVisible(false);
    ui->ip->horizontalHeader()->setVisible(false);
    ui->add_info->verticalHeader()->setVisible(false);
    ui->add_info->horizontalHeader()->setVisible(false);
    ui->add_info->setColumnCount(2);
    ui->add_info->setRowCount(5);

    QTableWidgetItem *item = ui->ip->item(0,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(0,0, item);
    }
    item->setText("Player");
    item->setFont(bold_font);

    item = ui->ip->item(0,1);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(0,1, item);
    }
    item->setText("Quality Points");
    item->setFont(bold_font);

    item = ui->ip->item(0,2);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(0,2, item);
    }
    item->setText("Learning Chips");
    item->setFont(bold_font);

    item = ui->ip->item(0,3);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(0,3, item);
    }
    item->setText("Craft Chips");
    item->setFont(bold_font);

    item = ui->ip->item(0,4);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(0,4, item);
    }
    item->setText("Integrity Chips");
    item->setFont(bold_font);

    item = ui->ip->item(0,5);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(0,5, item);
    }
    item->setText("Learning Chips");
    item->setFont(bold_font);

    item = ui->ip->item(1,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(1,0, item);
    }
    item->setText(main_player_name + "*");

    item = ui->ip->item(2,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(2,0, item);
    }
    item->setText(ai_player1_name);

    item = ui->ip->item(3,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->ip->setItem(3,0, item);
    }
    item->setText(ai_player2_name);

    item = ui->add_info->item(0,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->add_info->setItem(0,0, item);
    }
    item->setText("Current Player");
    item->setFont(bold_font);

    item = ui->add_info->item(1,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->add_info->setItem(1,0, item);
    }
    item->setText("Current Room");
    item->setFont(bold_font);

    item = ui->add_info->item(2,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->add_info->setItem(2,0, item);
    }
    item->setText("Cards in deck");
    item->setFont(bold_font);

    item = ui->add_info->item(3,0);
    if(!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->add_info->setItem(3,0, item);
    }
    item->setText("Discard cards");
    item->setFont(bold_font);
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
    QListWidgetItem* current_room = ui->room_list->currentItem();
    int user_data = current_room->data(Qt::UserRole).toInt();

    qDebug()<<human_player_turns;
    if(human_player_turns < 3)
    {
        human_player_turns = human_player_turns + 1;
        //relocate main_player as per selected room
        this->relocate(user_data,main_player,0);
        ui->moves->addItem("Main player moved to " + QString::number(user_data));
    }

    else if(human_player_turns = 3)
    {
        human_player_turns = human_player_turns + 1;
        //relocate main_player as per selected room
        this->relocate(user_data,main_player,0);
        ui->moves->addItem("Main player moved to " + QString::number(user_data));

        ui->move->setEnabled(false);
    }
    else
    {
        //move ai player to random available room
        int pos_ai_1 = this->move_ai_player(ai_player1,pos_ai_player[0], 18);

        //ui->move_ai_1->setText("First AI player moved to " + \
          //                     QString::number(pos_ai_1));

        int pos_ai_2 = this->move_ai_player(ai_player2,pos_ai_player[1],36);

        //ui->move_ai_2->setText("Second AI player moved to " + \
          //                     QString::number(pos_ai_2));

        //render the list of rooms
    }
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
    ui->room_list->clear();

    DataProcessing data;

    //get accessible rooms
    QJsonArray accessibles = data.get_accessible(place_id);

    //get title of rooms and add them to list with
    int json_index;
    for(json_index = 0; json_index < accessibles.size(); json_index++)
    {
        int room_id = accessibles[json_index].toInt();
        QString title = data.get_title(room_id);
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setData(Qt::UserRole, QVariant(room_id));
        newItem->setText(title);
        ui->room_list->addItem(newItem);
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
    ui->room_list->show();
    ui->move->show();
    ui->draw_card->show();
    ui->play_card->show();
    ui->move->setEnabled(false);
    ui->play_card->setEnabled(false);
    setup_tables();
    GamePlay game;
    game.initialize_map_with_objects();
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

void MainWindow::set_cards_in_hand()
{
    GamePlay game_play;
    game_play.randomize_deck();
    for(int i=1; i<=5; i++)
    {
        qDebug()<<i;
        int not_in_hand = 1;
        int card_id = MainWindow::gen_rand_number(51);
        int card = GamePlay::complete_card_deck.value(card_id);
        do
        {
            if(!GamePlay::cards_in_hand.contains(card))
            {
                if(card != 0)
                {
                    GamePlay::cards_in_hand.insert(i-1, card);
                    not_in_hand = 0;
                    qDebug()<<"position:"<<i<<" value:"<<card;
                    qDebug()<<"card"<<" "<<card;
                }
            }

        }
        while(not_in_hand != 0);
    }
    qDebug()<<"Final Size:"<<GamePlay::cards_in_hand.size();
    for(int i = 0; i < GamePlay::cards_in_hand.size(); i++)
    {
        qDebug()<<"final:"<<GamePlay::cards_in_hand.value(i);
    }

}

void MainWindow::set_icon_as_card()
{
    QString top_deck_card = QString::number(GamePlay::cards_in_hand.value(
                                                GamePlay::top_card_in_hand
                                                ) + 1);
    QString card_name = ":/images/resources/" + top_deck_card + ".png";
    QPixmap* top_card = new QPixmap(card_name);
    qDebug()<<card_name;
    QIcon ButtonIcon(*top_card);
    ui->card_holder->setIcon(QIcon());
    ui->card_holder->setIcon(ButtonIcon);
    ui->card_holder->setIconSize(top_card->rect().size()/1.8);
}

void MainWindow::on_card_holder_clicked()
{
    GamePlay::top_card_in_hand = GamePlay::top_card_in_hand + 1;
    if(GamePlay::top_card_in_hand >= GamePlay::cards_in_hand.size() ||
            GamePlay::top_card_in_hand < 0)
    {
        GamePlay::top_card_in_hand = 0;
        set_icon_as_card();
    }
    else
        set_icon_as_card();
}

void MainWindow::on_draw_card_clicked()
{
    int already_in_hand = 1;
    do
    {
        int top_of_deck = GamePlay::complete_card_deck.value(0);
        if(!GamePlay::cards_in_hand.contains(top_of_deck))
        {
             GamePlay::complete_card_deck.removeFirst();
             GamePlay::cards_in_hand.insert(0,top_of_deck);
             GamePlay::top_card_in_hand = 0;
             set_icon_as_card();
             ui->draw_card->setEnabled(false);
             ui->play_card->setEnabled(true);
             ui->move->setEnabled(true);
             already_in_hand = 0;
        }
    }while(already_in_hand != 0);
}

void MainWindow::on_play_card_clicked()
{

}
