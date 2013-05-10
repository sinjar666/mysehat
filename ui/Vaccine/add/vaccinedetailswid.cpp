#include "vaccinedetailswid.h"

VaccineDetailsWid::VaccineDetailsWid(QWidget *parent) :
    QWidget(parent)
{
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit();
    date_l = new QLabel(tr("Date Administered"));
    date_e = new QDateEdit(QDate::currentDate());
    validity_l = new QLabel(tr("Validity (months)"));
    validity_e = new QSpinBox();
    validity_e->setMinimum(0);
    lay = new QGridLayout(this);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(validity_l,2,0);
    lay->addWidget(validity_e,2,1);
}

QDate VaccineDetailsWid::getDate()   {
    return date_e->date();
}

quint16 VaccineDetailsWid::getValidity()    {
    return ((quint16)validity_e->value());
}

QString VaccineDetailsWid::getName()    {
    return name_e->text();
}

void VaccineDetailsWid::resetAll()  {
    name_e->clear();
    date_e->setDate(QDate::currentDate());
    validity_e->setValue(0);
}
