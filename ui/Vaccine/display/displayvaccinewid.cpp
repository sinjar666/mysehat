#include "displayvaccinewid.h"

DisplayVaccineWid::DisplayVaccineWid(Vaccine *arg, QWidget *parent) :
    QWidget(parent)
{
    model = arg;
    lay =new QGridLayout(this);
    name_l = new QLabel(tr("Name of Vaccine:"));
    name_e = new QLabel(model->getName());
    validity_l = new QLabel(tr("Validity"));
    validity_e = new QLabel(QString::number(model->getValidity()));
    date_l = new QLabel(tr("Date:"));
    date_e = new QLabel(model->getDate().toString());
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(validity_l,1,0);
    lay->addWidget(validity_e,1,1);
    lay->addWidget(date_l,2,0);
    lay->addWidget(date_e,2,1);
}
