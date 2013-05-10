#ifndef EDITLINKSDIALOG_H
#define EDITLINKSDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QListWidgetItem>
#include "search-engine/engine/engine.h"
#include "xml/Symptom/xsymptom.h"
#include "xml/Surgery/xsurgery.h"
#include "xml/Drug/xdrug.h"
#include "xml/Investigation/xinvestigation.h"
#include "xml/Appointment/xappointment.h"
#include "model/appointment.h"
#include "model/drug.h"
#include "model/investigation.h"
#include "model/surgery.h"
#include "model/symptom.h"

class EditLinksDialog : public QDialog
{
    Q_OBJECT
    Appointment *model;
    Engine::Filters type;
    QListWidget *list_widget;
    QPushButton *del_b,*all_b;
    QStringList listModel;
    QGridLayout *lay;
    QString path_model;

    QList<symptomComplained> s_list;
    QList<investigationAdvised> i_list;
    QList<surgeryAdvised> sur_list;
    QList<drugPrescribed> d_list;
public:
    explicit EditLinksDialog(QString path_a,Appointment *model_a,Engine::Filters type_a,QWidget *parent = 0);
    
signals:
    
public slots:
    void performDelete();
    void selectAll();
    
};

#endif // EDITLINKSDIALOG_H
