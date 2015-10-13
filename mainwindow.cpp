#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::relocate(QWidget *parent){
    int x = parent->x();
    int y = parent->y();
    parent->move(x - 2, y - 3);
}

void MainWindow::on_move_clicked()
{
    this->relocate(ui->player1);
    //slot to move player.
}
