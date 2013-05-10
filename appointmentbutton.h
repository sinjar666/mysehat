#ifndef APPOINTMENTBUTTON_H
#define APPOINTMENTBUTTON_H

#include <QPushButton>
#include <QSize>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>

#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"

class AppointmentButton : public QPushButton
{
    Q_OBJECT
    QString path;
    QHBoxLayout *h_layout;
    QDate date_value;
    QString doc_name;
    QLabel *date_l,*docname_l;
    Appointment *model;
    XAppointment *xappoint;

public:
    explicit AppointmentButton(QString path_a,QWidget *parent = 0);
    QSize sizeHint() const;

signals:
    void AppointItemClicked(QString);

public slots:
    void appointClicked();

};

#endif // APPOINTMENTBUTTON_H
