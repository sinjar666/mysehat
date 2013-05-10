#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include "../../search-engine/engine/engine.h"
#include "../../search-engine/engine/indexitem.h"
#include "../../model/symptom.h"
#include "../../model/drug.h"
#include "../../model/surgery.h"
#include "../../model/investigation.h"
#include "../../xml/Symptom/xsymptom.h"
#include "../../xml/Drug/xdrug.h"
#include "../../xml/Surgery/xsurgery.h"
#include "../../xml/Investigation/xinvestigation.h"
#include "../../model/appointment.h"

class SearchDialog : public QDialog
{
    Q_OBJECT
private:
    Engine::Filters type;
    QStringList view;
    QList<IndexItem> results;
    QGridLayout *lay;
    QListWidget *view_list;
    QLineEdit *searchbox;
    QDateEdit *date_e;
    QPushButton *add_b,*search_b;
    QSpinBox *dosage_e,*duration_e;
    Engine *engine;
    QString path;
    Appointment *res_model;


public:
    explicit SearchDialog(QString path_a,Engine::Filters type_a,
                          Appointment *res_m,QWidget *parent=0);
    ~SearchDialog();
signals:
    
public slots:
    void performSearch();
    void onAddClicked();
    
};

#endif // SEARCHDIALOG_H
