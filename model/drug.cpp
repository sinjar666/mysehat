#include "drug.h"

Drug::Drug(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    date = new QDate();
    name = new QString();
    linkedTo = new QList<ID_TYPE>();
}

Drug::~Drug()   {
    delete(id);
    delete(name);
    delete(date);
}

void Drug::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Drug::setDate(QDate arg)    {
    *date=arg;
}

QDate Drug::getDate()    {
    return *date;
}

void Drug::setName(QString arg) {
    *name=arg;
}

QString Drug::getName() {
    return *name;
}

void Drug::setDuration(quint16 arg) {
    duration=arg;
}
quint16 Drug::getDuration() {
    return duration;
}

QList<ID_TYPE> Drug::getLinkedTo()   {
    return *linkedTo;
}

bool Drug::addLink(ID_TYPE arg)  {
    if(!linkedTo->contains(arg))    {
        linkedTo->append(arg);
        return true;
    }
    else return false;
}

bool Drug::removeLink(QString arg)   {
    return ((linkedTo->removeAll(arg))!=0)?true:false;

}

