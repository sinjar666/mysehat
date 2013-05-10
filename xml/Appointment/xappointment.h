#ifndef XAPPOINTMENT_H
#define XAPPOINTMENT_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDomAttr>
#include "model/appointment.h"

class XAppointment : public QObject
{
    Q_OBJECT
    Appointment *obj;
    QString filepath;
public:
    explicit XAppointment(Appointment *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XAPPOINTMENT_H
