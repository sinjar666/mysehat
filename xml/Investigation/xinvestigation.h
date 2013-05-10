#ifndef XINVESTIGATION_H
#define XINVESTIGATION_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "model/investigation.h"

class XInvestigation : public QObject
{
    Q_OBJECT
    Investigation *obj;
    QString filepath;
public:
    explicit XInvestigation(Investigation *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XINVESTIGATION_H
