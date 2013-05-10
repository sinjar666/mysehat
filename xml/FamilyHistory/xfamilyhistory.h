#ifndef XFAMILYHISTORY_H
#define XFAMILYHISTORY_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "model/familyhistory.h"

class XFamilyHistory : public QObject
{
    Q_OBJECT
    FamilyHistory *obj;
    QString filepath;

public:
    explicit XFamilyHistory(FamilyHistory *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();
signals:

public slots:

};

#endif // XFAMILYHISTORY_H
