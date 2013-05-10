#ifndef XDRUG_H
#define XDRUG_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "model/drug.h"

class XDrug : public QObject
{
    Q_OBJECT
    Drug *obj;
    QString filepath;

public:
    explicit XDrug(Drug *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XDRUG_H
