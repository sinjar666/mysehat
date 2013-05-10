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

#ifndef DISPLAYAPPOINTMENTWID_H
#define DISPLAYAPPOINTMENTWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "model/appointment.h"
#include "../../ShowItemsDialog/showitemsdialog.h"
#include "model/drug.h"
#include "xml/Drug/xdrug.h"
#include "../../Drug/display/displaydrugwid.h"
#include "../../Symptom/display/displaysymptomwid.h"
#include "../../Surgery/display/displaysurgerywid.h"
#include "../../Investigation/display/displayinvestigationwid.h"


class DisplayAppointmentWid : public QWidget
{
    Q_OBJECT
    QLabel *name_l,*name_e,*date_l,*date_e,*time_l,*time_e;
    QString path,to_open;
    Appointment *model;
    QGridLayout *lay;
    QPushButton *sym_b,*drug_b,*sur_b,*inv_b;
    int disp_wid_type;
    /* 0 = symptom
      1 = drug
      2 = surgery
      3 = inv
    */

public:
    explicit DisplayAppointmentWid(bool links,Appointment *arg,QWidget *parent=0);
    
signals:
    
public slots:
    void showSymptoms();
    void showDrugs();
    void showSurgery();
    void showInvestigations();
    void displayWidget();
    
};

#endif // DISPLAYAPPOINTMENTWID_H
