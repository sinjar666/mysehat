#ifndef ADDITEMWIDGET_H
#define ADDITEMWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QDir>

#include "additembutton.h"

#include "ui/Vaccine/add/addvaccinewid.h"
#include "ui/Allergen/add/addallergenwid.h"
#include "ui/Investigation/add/addinvestigationwid.h"
#include "ui/Appointment/add/addappointmentwid.h"
#include "ui/Drug/add/adddrugwid.h"
#include "ui/FamilyHistory/add/addfamilyhistorywid.h"
#include "ui/Surgery/add/addsurgerywid.h"
#include "ui/Symptom/add/addsymptomwid.h"

class AddItemWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *lay;
    AddItemButton *app_b,*sym_b,*inv_b,*sur_b,*drug_b,*all_b,*vac_b,*fam_b;
    QLabel *title_l;
    QDir *pathdir;

    AddAllergenWid *add_allergen;
    AddVaccineWid *add_vaccine;
    AddInvestigationWid *add_invest;
    AddAppointmentWid *add_appoint;
    AddDrugWid *add_drug;
    AddFamilyHistoryWid *add_family;
    AddSurgeryWid *add_surgery;
    AddSymptomWid *add_symptom;

public:
    explicit AddItemWidget(QDir *pathdir_a,QWidget *parent = 0);

signals:

public slots:
    void AddAllergenClicked();
    void AddVaccineClicked();
    void AddInvestigationClicked();
    void AddAppointmentClicked();
    void AddDrugClicked();
    void AddFamilyHistoryClicked();
    void AddSurgeryClicked();
    void AddSymptomClicked();
};

#endif // ADDITEMWIDGET_H
