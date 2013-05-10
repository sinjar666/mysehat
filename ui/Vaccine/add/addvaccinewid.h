#ifndef ADDVACCINEWID_H
#define ADDVACCINEWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QErrorMessage>

#include "vaccinebottomwid.h"
#include "vaccinedetailswid.h"
#include "model/vaccine.h"
#include "xml/Vaccine/xvaccine.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"

class AddVaccineWid : public QWidget
{
    Q_OBJECT
    VaccineDetailsWid *det_w;
    VaccineBottomWid *bottom;
    QVBoxLayout *lay;
    QString path;
public:
    explicit AddVaccineWid(QString rootdir, QWidget *parent=0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // ADDVACCINEWID_H
