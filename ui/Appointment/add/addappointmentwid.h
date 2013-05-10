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

#ifndef ADDAPPOINTMENTWID_H
#define ADDAPPOINTMENTWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QMultiMap>
#include <QDataStream>
#include <QTextStream>
#include <QErrorMessage>

#include "appointmentbottombar.h"
#include "appointmentdatetimewid.h"
#include "appointmentlinkwid.h"
#include "appointmentnamewid.h"
#include "model/appointment.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "xml/Appointment/xappointment.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "ui/SearchDialog/searchdialog.h"

class AddAppointmentWid : public QWidget
{
    Q_OBJECT
    AppointmentBottomBar *bottom;
    AppointmentDateTimeWid *dt;
    AppointmentLinkWid *link_w;
    AppointmentNameWid *name_w;
    QVBoxLayout *lay;
    QMultiMap<QDate,QString> map_date;
    Appointment *model;
    QString path;

    QList<symptomComplained> syms;
    QList<drugPrescribed> drug;
    QList<surgeryAdvised> sur;
    QList<investigationAdvised> inv;
public:
    explicit AddAppointmentWid(QString rootdir,QWidget *parent = 0);
    
signals:
    
public slots:
    void performAddLinks(int index);
    void performReset();
    void performSave();
    
};

#endif // ADDAPPOINTMENTWID_H

