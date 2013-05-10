#ifndef DISPLAYINVESTIGATIONWID_H
#define DISPLAYINVESTIGATIONWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include "model/investigation.h"
#include "ui/ShowItemsDialog/showitemsdialog.h"
#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"
#include "ui/Appointment/display/displayappointmentwid.h"
#include "ui/Investigation/display/displayreportsdialog.h"

class DisplayInvestigationwid : public QWidget
{
    Q_OBJECT
    Investigation *model;
    QPushButton *app_button,*img_button;
    QGridLayout *g_layout;
    QLabel *datetime,*datetimevalue,*type,*typevalue,*detail_l,*detailvalue,*report,*reportvalue;
    QString get_date,get_time,get_type,get_detail,get_report,to_open;

public:
    explicit DisplayInvestigationwid(Investigation *arg,QWidget *parent = 0);

signals:

public slots:
    void displaylinks();
    void displayAppointment();
    void dipslayImage();

};

#endif // DISPLAYINVESTIGATIONWID_H
