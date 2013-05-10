#include "appointmentnamewid.h"

AppointmentNameWid::AppointmentNameWid(QWidget *parent) :
    QWidget(parent)
{
    name_l = new QLabel(tr("Doctor's Name"));
    name_e = new QLineEdit();
    lay = new QHBoxLayout(this);
    lay->addWidget(name_l);
    lay->addWidget(name_e);
}

void AppointmentNameWid::resetAll() {
    name_e->clear();

}

QString AppointmentNameWid::getName()   {
    return name_e->text();
}
