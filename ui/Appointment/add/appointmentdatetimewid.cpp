#include "appointmentdatetimewid.h"

AppointmentDateTimeWid::AppointmentDateTimeWid(QWidget *parent) :
    QWidget(parent)
{
    datetime_e = new QDateTimeEdit();
    datetime_e->setDateTime(QDateTime::currentDateTime());
    datetime_l = new QLabel(tr("Date/Time"));
    lay = new QHBoxLayout(this);
    lay->addWidget(datetime_l);
    lay->addWidget(datetime_e);
}

void AppointmentDateTimeWid::resetAll() {
    datetime_e->setDate(QDate::currentDate());
    datetime_e->setTime(QTime::currentTime());
}

QDate AppointmentDateTimeWid::getDate() {
    return datetime_e->date();
}

QTime AppointmentDateTimeWid::getTime() {
    return datetime_e->time();
}
