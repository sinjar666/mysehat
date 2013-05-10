#include "surgery.h"

Surgery::Surgery(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    details = new QString();
    linkedTo = new QList<ID_TYPE>();
    date = new QDate();
}

Surgery::~Surgery() {
    delete(id);
    delete(details);
    delete(linkedTo);
    delete(date);
}

void Surgery::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Surgery::setDate(QDate arg)    {
    *date=arg;
}

QDate Surgery::getDate()    {
    return *date;
}

void Surgery::setDetails(QString arg) {
    *details=arg;
}

QString Surgery::getDetails() {
    return *details;
}

QList<ID_TYPE> Surgery::getLinkedTo()   {
    return *linkedTo;
}

bool Surgery::addLink(ID_TYPE arg)  {
    if(!linkedTo->contains(arg))    {
        linkedTo->append(arg);
        return true;
    }
    else return false;
}

bool Surgery::removeLink(QString arg)   {
    return ((linkedTo->removeAll(arg))!=0)?true:false;

}
