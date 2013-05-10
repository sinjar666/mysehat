#ifndef SHOWITEMSDIALOG_H
#define SHOWITEMSDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QLabel>
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

class ShowItemsDialog : public QDialog
{
    Q_OBJECT
    QVBoxLayout *lay;
    QListWidget *view;
    QString *val;
    Engine::Filters type;
    QList<QString> items;
public:
    explicit ShowItemsDialog(Engine::Filters arg,QList<QString> items_arg,QString *val_a,QWidget *parent = 0);
    
signals:
    
public slots:
    void onItemDoubleClicked(QListWidgetItem *item);
    
};

#endif // SHOWITEMSDIALOG_H
