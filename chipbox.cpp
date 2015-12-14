#include "chipbox.h"
#include "ui_chipbox.h"
#include "cards.h"

bool ChipBox::learning_enabled = true;
bool ChipBox::craft_enabled = true;
bool ChipBox::integrity_enabaled = true;

ChipBox::ChipBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChipBox)
{
    ui->setupUi(this);
    this->setWindowTitle("Chip Selection");
    if(!learning_enabled)
        ui->learning_chip->setEnabled(false);
    if(!craft_enabled)
        ui->craft_chip->setEnabled(false);
    if(!integrity_enabaled)
        ui->integrity_chip->setEnabled(false);
    this->exec();
}

ChipBox::~ChipBox()
{
    delete ui;
}

void ChipBox::on_integrity_chip_clicked()
{
    GamePlay::integrity_chips[MainWindow::current_player_id] += 1;
    this->close();
}

void ChipBox::on_learning_chip_clicked()
{
    GamePlay::learning_chips[MainWindow::current_player_id] += 1;
    this->close();
}

void ChipBox::on_craft_chip_clicked()
{
    GamePlay::craft_chips[MainWindow::current_player_id] += 1;
    this->close();
}
