/****************************************************************************************
 * Copyright (c) 2012 Srijan Mukherjee <srijanmukherjee06@yahoo.com>                    *
 * Copyright (c) 2012 Tumul Richesh <tumullko@gmail.com>                                *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 3 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

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
