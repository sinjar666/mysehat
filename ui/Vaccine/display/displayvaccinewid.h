#ifndef DISPLAYVACCINEWID_H
#define DISPLAYVACCINEWID_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "model/vaccine.h"

class DisplayVaccineWid : public QWidget
{
    Q_OBJECT
    QGridLayout *lay;
    QLabel *name_l,*name_e,*validity_l,*validity_e,*date_l,*date_e;
    Vaccine *model;
public:
    explicit DisplayVaccineWid(Vaccine *arg,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DISPLAYVACCINEWID_H
