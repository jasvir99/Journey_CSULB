#include "discardcard.h"
#include "ui_discardcard.h"
#include "cards.h"

bool DiscardCard::card_discarded = false;

DiscardCard::DiscardCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiscardCard)
{
    ui->setupUi(this);
    this->setWindowTitle("Card Selection");
    set_discard_list();
    this->exec();
}

DiscardCard::~DiscardCard()
{
    delete ui;
}

void DiscardCard::set_discard_list()
{
    QString top_deck_card = QString::number(GamePlay::cards_in_hand.value(
                                                GamePlay::top_card_in_hand
                                                ));
    QString card_name = ":/images/resources/" + top_deck_card + ".png";
    QPixmap* top_card = new QPixmap(card_name);
    qDebug()<<card_name;
    QIcon ButtonIcon(*top_card);
    ui->card_to_be_discarded->setIcon(QIcon());
    ui->card_to_be_discarded->setIcon(ButtonIcon);
    ui->card_to_be_discarded->setIconSize(top_card->rect().size()/1.4);
}

void DiscardCard::on_cancel_clicked()
{
    this->close();
}

void DiscardCard::on_card_to_be_discarded_clicked()
{
    GamePlay::top_card_in_hand = GamePlay::top_card_in_hand + 1;
    if(GamePlay::top_card_in_hand >= GamePlay::cards_in_hand.size() ||
            GamePlay::top_card_in_hand < 0)
    {
        GamePlay::top_card_in_hand = 0;
        set_discard_list();

    }
    else
    {
        set_discard_list();

    }
}

void DiscardCard::on_discard_clicked()
{
    int top_card = GamePlay::cards_in_hand.value(GamePlay::top_card_in_hand);
    GamePlay::discarded_card_deck.append(top_card);
    GamePlay::cards_in_hand.removeAt(GamePlay::top_card_in_hand);
    if(GamePlay::top_card_in_hand > 0)
    {
        GamePlay::top_card_in_hand = GamePlay::top_card_in_hand - 1;
    }

    else
    {
        GamePlay::top_card_in_hand = 0;
    }

    MainWindow window(false);
    window.set_icon_as_card();
    window.refresh_information_panel();

    card_discarded = true;


    this->close();
}
