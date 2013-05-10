#ifndef XSYMPTOM_H
#define XSYMPTOM_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "model/symptom.h"

class XSymptom : public QObject
{
    Q_OBJECT
    Symptom *obj;
    QString filepath;
public:
    explicit XSymptom(Symptom *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XSYMPTOM_H
