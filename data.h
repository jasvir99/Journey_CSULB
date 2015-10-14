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

