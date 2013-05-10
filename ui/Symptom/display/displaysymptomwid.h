#ifndef DISPLAYSYMPTOMWID_H
#define DISPLAYSYMPTOMWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include "model/symptom.h"
#include "ui/Appointment/display/displayappointmentwid.h"
#include "xml/Appointment/xappointment.h"
#include "model/appointment.h"
#include "ui/ShowItemsDialog/showitemsdialog.h"

class DisplaySymptomWid : public QWidget
{
    Q_OBJECT
    Symptom *model;
    QGridLayout *g_layout;
    QLabel *desc,*charac,*descvalue,*characvalue;
    QPushButton *app_button;
    QString to_open;

public:
    explicit DisplaySymptomWid(Symptom *arg,QWidget *parent = 0);

signals:

public slots:
    void displaylinks();
    void displayAppointment();

};

#endif // DISPLAYSYMPTOMWID_H
