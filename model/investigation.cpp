#include "investigation.h"

Investigation::Investigation(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    date = new QDate();
    time = new QTime();
    details = new QString();
    linkedTo = new QList<ID_TYPE>();
    report = new QString();
}

Investigation::~Investigation() {
    delete(id);
    delete(date);
    delete(time);
    delete(details);
    delete(linkedTo);
    delete(report);
}

void Investigation::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Investigation::setDate(QDate arg)    {
    *date=arg;
}

QDate Investigation::getDate()    {
    return *date;
}

void Investigation::setTime(int hour, int min)  {
    time->setHMS(hour,min,0);
}

void Investigation::setTime(QTime arg)    {
    *time = arg;
}

QTime Investigation::getTime()    {
    return *time;
}

void Investigation::setType(Type arg)   {
    type=arg;
}
Investigation::Type Investigation::getType()   {
    return type;
}


void Investigation::setDetails(QString arg) {
    *details=arg;
}

QString Investigation::getDetails() {
    return *details;
}

QList<ID_TYPE> Investigation::getLinkedTo()   {
    return *linkedTo;
}

bool Investigation::addLink(ID_TYPE arg)  {
    if(!linkedTo->contains(arg))    {
        linkedTo->append(arg);
        return true;
    }
    else return false;
}

bool Investigation::removeLink(QString arg)   {
    return ((linkedTo->removeAll(arg))!=0)?true:false;

}
QString Investigation::getReport() {
    return *report;
}

void Investigation::setReport(QString arg) {
    *report=arg;
}
