#include "vaccine.h"

Vaccine::Vaccine(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    name = new QString();
    date = new QDate();
}

Vaccine::~Vaccine() {
    delete(id);
    delete(name);
    delete(date);
}

void Vaccine::setName(QString arg)  {
    *name=arg;
}
QString Vaccine::getName()  {
    return *name;
}

void Vaccine::setValidity(quint16 arg)  {
    validity=arg;
}
quint16 Vaccine::getValidity()  {
    return validity;
}

void Vaccine::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Vaccine::setDate(QDate arg)    {
    *date=arg;
}

QDate Vaccine::getDate()    {
    return *date;
}
