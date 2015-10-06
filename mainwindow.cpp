#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap* image = new QPixmap(":/images/resources/board.png");
    QPixmap* card = new QPixmap(":/images/resources/card1.png");

    ui->setupUi(this);
    ui->mainImage->setPixmap(*image);
    ui->cards->setPixmap(*card);
    this->setWindowTitle("Journey at CSULB");
}

MainWindow::~MainWindow()
{
    delete ui;
}
