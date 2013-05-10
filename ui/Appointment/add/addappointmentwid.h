#ifndef ADDAPPOINTMENTWID_H
#define ADDAPPOINTMENTWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QMultiMap>
#include <QDataStream>
#include <QTextStream>
#include <QErrorMessage>

#include "appointmentbottombar.h"
#include "appointmentdatetimewid.h"
#include "appointmentlinkwid.h"
#include "appointmentnamewid.h"
#include "model/appointment.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "xml/Appointment/xappointment.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "ui/SearchDialog/searchdialog.h"

class AddAppointmentWid : public QWidget
{
    Q_OBJECT
    AppointmentBottomBar *bottom;
    AppointmentDateTimeWid *dt;
    AppointmentLinkWid *link_w;
    AppointmentNameWid *name_w;
    QVBoxLayout *lay;
    QMultiMap<QDate,QString> map_date;
    Appointment *model;
    QString path;

    QList<symptomComplained> syms;
    QList<drugPrescribed> drug;
    QList<surgeryAdvised> sur;
    QList<investigationAdvised> inv;
public:
    explicit AddAppointmentWid(QString rootdir,QWidget *parent = 0);
    
signals:
    
public slots:
    void performAddLinks(int index);
    void performReset();
    void performSave();
    
};

#endif // ADDAPPOINTMENTWID_H

