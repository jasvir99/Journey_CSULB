/**
 *
 *       \file       data.h
 *
 *       \brief      Header file for data.cpp which includes data processing
 *                   functions.
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

#ifndef DATA
#define DATA

#include "QFile"
#include "QtGui"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>

namespace data {
class DataProcessing;
}

class DataProcessing : public QMainWindow
{
    Q_OBJECT

public:
    QJsonObject read_json(int place_id);
    int get_xvalue(int place_id);
    int get_yvalue(int place_id);
    QJsonArray get_accessible(int place_id);
    QString get_title(int place_id);
};

#endif // DATA

