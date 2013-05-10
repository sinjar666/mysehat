#ifndef XALLERGEN_H
#define XALLERGEN_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "model/allergen.h"

class XAllergen : public QObject
{
    Q_OBJECT
    Allergen *obj;
    QString filepath;
public:
    explicit XAllergen(Allergen *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XALLERGEN_H
