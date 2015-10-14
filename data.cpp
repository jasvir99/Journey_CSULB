/**
 *
 *       \file       data.cpp
 *
 *       \brief      Include functions for data processing.
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

#include "data.h"

using namespace std;

QJsonObject DataProcessing::read_json(int place_id)
{
    QString pla = QString::number(place_id);
    QString val;
    QFile file;
    file.setFileName(":/resources/info.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject obj = doc.object();
    QJsonValue value = obj.value(pla);
    QJsonObject obj2 = value.toObject();
    return obj2;
}

int DataProcessing::get_xvalue(int place_id)
{
    QJsonObject obj = this->read_json(place_id);
    int x_val = obj["x_value"].toInt();
    return x_val;
}

int DataProcessing::get_yvalue(int place_id)
{
    QJsonObject obj = this->read_json(place_id);
    int y_val = obj["y_value"].toInt();
    return y_val;
}

QJsonArray DataProcessing::get_accessible(int place_id)
{
    QJsonObject obj = this->read_json(place_id);
    QJsonArray accessible = obj["accessible"].toArray();
    return accessible;
}

QString DataProcessing::get_title(int place_id)
{
    QJsonObject obj = this->read_json(place_id);
    QString title = obj["title"].toString();
    //qDebug()<<title;
    return title;
}
