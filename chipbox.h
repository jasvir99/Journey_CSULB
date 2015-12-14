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
    explicit ChipBox(QWidget *parent = 0);
    ~ChipBox();
    static bool integrity_enabaled;
    static bool craft_enabled;
    static bool learning_enabled;

private slots:
    void on_integrity_chip_clicked();

    void on_learning_chip_clicked();

    void on_craft_chip_clicked();

private:
    Ui::ChipBox *ui;
};

#endif // CHIPBOX_H
