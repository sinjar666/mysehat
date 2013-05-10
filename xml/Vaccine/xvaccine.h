#ifndef XVACCINE_H
#define XVACCINE_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "model/vaccine.h"

class XVaccine : public QObject
{
    Q_OBJECT
    Vaccine *obj;
    QString filepath;
public:
    explicit XVaccine(Vaccine *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XVACCINE_H
