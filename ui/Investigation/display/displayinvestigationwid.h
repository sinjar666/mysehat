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

#ifndef DISPLAYINVESTIGATIONWID_H
#define DISPLAYINVESTIGATIONWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include "model/investigation.h"
#include "ui/ShowItemsDialog/showitemsdialog.h"
#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"
#include "ui/Appointment/display/displayappointmentwid.h"
#include "ui/Investigation/display/displayreportsdialog.h"

class DisplayInvestigationwid : public QWidget
{
    Q_OBJECT
    Investigation *model;
    QPushButton *app_button,*img_button;
    QGridLayout *g_layout;
    QLabel *datetime,*datetimevalue,*type,*typevalue,*detail_l,*detailvalue,*report,*reportvalue;
    QString get_date,get_time,get_type,get_detail,get_report,to_open;

public:
    explicit DisplayInvestigationwid(Investigation *arg,QWidget *parent = 0);

signals:

public slots:
    void displaylinks();
    void displayAppointment();
    void dipslayImage();

};

#endif // DISPLAYINVESTIGATIONWID_H
