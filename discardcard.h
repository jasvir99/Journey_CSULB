#ifndef DISCARDCARD_H
#define DISCARDCARD_H

#include <QDialog>

namespace Ui {
class DiscardCard;
}

class DiscardCard : public QDialog
{
    Q_OBJECT

public:
    explicit DiscardCard(QWidget *parent = 0);
    ~DiscardCard();
    void set_discard_list();
    static bool card_discarded;

private slots:
    void on_cancel_clicked();

    void on_card_to_be_discarded_clicked();

    void on_discard_clicked();

private:
    Ui::DiscardCard *ui;
};

#endif // DISCARDCARD_H
