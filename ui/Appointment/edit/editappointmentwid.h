#ifndef EDITAPPOINTMENTWID_H
#define EDITAPPOINTMENTWID_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QDateEdit>
#include <QTimeEdit>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QErrorMessage>

#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "KeyFinder/keyfinder.h"
#include "ui/SearchDialog/searchdialog.h"
#include "ui/Appointment/edit/editlinksdialog.h"

class EditAppointmentWid : public QWidget
{
    Q_OBJECT
    QGridLayout *lay;
    QLabel *name_l,*date_l,*time_l,*category_l;
    QLineEdit *name_e;
    QDateEdit *date_e;
    QTimeEdit *time_e;
    QComboBox *category_e;
    QPushButton *save_b,*reset_b,*viewLinks,*addLinks;
    IndexItem old_item;
    Appointment *model;
    QString path;

    QList<symptomComplained> syms;
    QList<drugPrescribed> drug;
    QList<surgeryAdvised> sur;
    QList<investigationAdvised> inv;
public:
    explicit EditAppointmentWid(QString path_a,IndexItem olditem,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    void onViewLinks();
    void onAddLinks();
    
};

#endif // EDITAPPOINTMENTWID_H
