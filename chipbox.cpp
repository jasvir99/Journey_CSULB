#include "chipbox.h"
#include "ui_chipbox.h"
#include "cards.h"

bool ChipBox::learning_enabled = true;
bool ChipBox::craft_enabled = true;
bool ChipBox::integrity_enabled = true;
bool ChipBox::got_integrity_chip = false;
bool ChipBox::got_learning_chip = false;
bool ChipBox::got_craft_chip = false;

ChipBox::ChipBox(bool main_player, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChipBox)
{
    ui->setupUi(this);
    if(main_player)
    {
        this->setWindowTitle("Chip Selection");
        if(!learning_enabled)
            ui->learning_chip->setEnabled(false);
        if(!craft_enabled)
            ui->craft_chip->setEnabled(false);
        if(!integrity_enabled)
            ui->integrity_chip->setEnabled(false);
        this->exec();
    }
}

ChipBox::~ChipBox()
{
    delete ui;
}

void ChipBox::on_integrity_chip_clicked()
{
    got_integrity_chip = true;
    this->close();
}

void ChipBox::on_learning_chip_clicked()
{
    got_learning_chip = true;

    this->close();
}

void ChipBox::on_craft_chip_clicked()
{
    got_craft_chip = true;

    this->close();
}

void ChipBox::chip_selection_ai(QList<int> enabled_chips, int player)
{
    int size = enabled_chips.size();
    MainWindow window(false);
    int temp = window.gen_rand_number(size);
    int chip_type = enabled_chips.value(temp);
    if(chip_type == 1)
    {
        GamePlay::integrity_chips[player] += 1;
    }

    else if(chip_type == 2)
    {
        GamePlay::learning_chips[player] += 1;
    }

    else
    {
        GamePlay::craft_chips[player] += 1;
    }
}
