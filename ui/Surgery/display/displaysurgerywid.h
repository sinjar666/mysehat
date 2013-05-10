#ifndef DISPLAYSURGERYWID_H
#define DISPLAYSURGERYWID_H

#include <QWidget>
#include <QString>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include "model/surgery.h"
#include "ui/Appointment/display/displayappointmentwid.h"
#include "xml/Appointment/xappointment.h"
#include "model/appointment.h"
#include "ui/ShowItemsDialog/showitemsdialog.h"

class DisplaySurgeryWid : public QWidget
{
    Q_OBJECT
    Surgery *model;
    QGridLayout *g_layout;
    QLabel *date,*datevalue,*details,*detailsvalue;
    QPushButton *app_button;
    QString to_open;
public:
    explicit DisplaySurgeryWid(Surgery *arg,QWidget *parent = 0);

signals:

public slots:
    void displaylinks();
    void displayAppointment();

};

#endif // DISPLAYSURGERYWID_H
