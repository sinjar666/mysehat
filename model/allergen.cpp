#include "allergen.h"

Allergen::Allergen(QObject *parent) :
    QObject(parent)
{
    name=new QString();
    date=new QDate();
    drug_id = new QString();
}

Allergen::~Allergen()   {
    delete(name);
    delete(date);
    delete(drug_id);
}

void Allergen::setName(QString arg) {
    *name=arg;
}
QString Allergen::getName()   {
    return *name;
}

void Allergen::setDate(int day, int month, int year)    {
    date->setDate(year,month,day);
}
void Allergen::setDate(QDate arg)   {
    *date=arg;
}
QDate Allergen::getDate()   {
    return *date;
}

void Allergen::setType(A_type arg)  {
    type=arg;
}

Allergen::A_type Allergen::getType()  {
    return type;
}

QString Allergen::getDrug() {
    return *drug_id;
}

void Allergen::setDrug(QString arg) {
    *drug_id=arg;
}
