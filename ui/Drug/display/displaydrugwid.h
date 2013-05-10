#ifndef DISPLAYDRUGWID_H
#define DISPLAYDRUGWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "model/drug.h"
#include "../../ShowItemsDialog/showitemsdialog.h"
#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"
#include "../../Appointment/display/displayappointmentwid.h"

class DisplayDrugWid : public QWidget
{
    Q_OBJECT
    QGridLayout *lay;
    QLabel *name_l,*name_e,*date_l,*date_e,*duration_l,*duration_e;
    QPushButton *app_b;
    Drug *model;
    QString path;
    QString to_open;
public:
    explicit DisplayDrugWid(Drug *arg,QWidget *parent=0);
    
signals:
    
public slots:
    void displayLinks();
    void displayAppointment();
    
};

#endif // DISPLAYDRUGWID_H
