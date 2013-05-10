#ifndef DELETEWID_H
#define DELETEWID_H

#include <QObject>
#include <QString>
#include <QList>
#include <QFile>

#include "search-engine/engine/engine.h"
#include "KeyFinder/keyfinder.h"
#include "search-engine/engine/indexitem.h"

#include "model/appointment.h"
#include "model/symptom.h"
#include "model/investigation.h"
#include "model/drug.h"
#include "model/surgery.h"
#include "model/familyhistory.h"
#include "model/vaccine.h"

#include "xml/Appointment/xappointment.h"
#include "xml/Symptom/xsymptom.h"
#include "xml/Investigation/xinvestigation.h"
#include "xml/Drug/xdrug.h"
#include "xml/Surgery/xsurgery.h"
#include "xml/Allergen/xallergen.h"
#include "xml/FamilyHistory/xfamilyhistory.h"
#include "xml/Vaccine/xvaccine.h"

class DeleteWid : public QObject
{
    Q_OBJECT
    QString path;
    QList<symptomComplained> syms;
    QList<drugPrescribed> drug;
    QList<surgeryAdvised> sur;
    QList<investigationAdvised> inv;

    Appointment *model_app;
    Symptom *model_sym;
    FamilyHistory *model_fam;
    Surgery *model_sur;
    Investigation *model_inv;
    Drug *model_drug;
    Vaccine *model_vac;

public:
    explicit DeleteWid(QString path_a,IndexItem old_item,QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DELETEWID_H
