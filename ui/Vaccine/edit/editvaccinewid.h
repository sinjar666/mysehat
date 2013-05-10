#ifndef EDITVACCINEWID_H
#define EDITVACCINEWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QErrorMessage>

#include "model/vaccine.h"
#include "xml/Vaccine/xvaccine.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "KeyFinder/keyfinder.h"

class EditVaccineWid : public QWidget
{
    Q_OBJECT
    QLabel *name_l,*date_l,*validity_l;
    QLineEdit *name_e;
    QDateEdit *date_e;
    QSpinBox *validity_e;
    QGridLayout *lay;
    QPushButton *save_b,*reset_b;
    QString path;
    IndexItem old_item;
    Vaccine *model;
    XVaccine *xml;
public:
    explicit EditVaccineWid(QString path_a,IndexItem olditem,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // EDITVACCINEWID_H
