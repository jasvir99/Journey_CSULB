#ifndef CHIPBOX_H
#define CHIPBOX_H

#include <QDialog>

namespace Ui {
class ChipBox;
}

class ChipBox : public QDialog
{
    Q_OBJECT

public:
    explicit ChipBox(bool main_player,QWidget *parent = 0);
    ~ChipBox();
    static bool integrity_enabled;
    static bool craft_enabled;
    static bool learning_enabled;
    static bool got_integrity_chip;
    static bool got_learning_chip;
    static bool got_craft_chip;
    /*
     * integrity chip = 1
     * learning chip = 2
     * craft chip = 3
     */
    void chip_selection_ai(QList<int> enabled_chip, int player);

private slots:
    void on_integrity_chip_clicked();

    void on_learning_chip_clicked();

    void on_craft_chip_clicked();

private:
    Ui::ChipBox *ui;
};

#endif // CHIPBOX_H
