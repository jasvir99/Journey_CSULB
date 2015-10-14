#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"

//Initializing static data members

QWidget* MainWindow::main_player = 0;
QWidget* MainWindow::ai_player1 = 0;
QWidget* MainWindow::ai_player2 = 0;
int MainWindow::init_x_value = 812;
int MainWindow::init_y_value = 1100;

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

int MainWindow::gen_rand_number()
{
    int b = qrand() % 3;
    return b;
}

void MainWindow::prepare_board()
{
    players.append(ui->player1);
    players.append(ui->player2);
    players.append(ui->player3);
    int a = this->gen_rand_number();
    main_player = players[a];
    main_player->setStyleSheet("color: red;");
    players.removeAt(a);
    ai_player1 = players[0];
    ai_player2 = players[1];
}

void MainWindow::relocate(int x, int y)
{
    main_player->move(x,y);
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
    int x_value = data.get_xvalue(user_data);
    int y_value = data.get_yvalue(user_data);
    this->relocate(x_value,y_value);
    this->render_room_list(current_index);


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
    ai_player1->move(init_x_value,init_y_value-15);
    ai_player2->move(init_x_value,init_y_value-30);
    ui->start->hide();
    ui->rooms->show();
    ui->move->show();
}
