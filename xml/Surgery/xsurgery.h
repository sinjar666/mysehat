#ifndef XSURGERY_H
#define XSURGERY_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "model/surgery.h"

class XSurgery : public QObject
{
    Q_OBJECT
    Surgery *obj;
    QString filepath;
public:
    explicit XSurgery(Surgery *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XSURGERY_H
