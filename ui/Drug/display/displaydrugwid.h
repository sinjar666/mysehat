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

#ifndef DISPLAYDRUGWID_H
#define DISPLAYDRUGWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "model/drug.h"
#include "../../ShowItemsDialog/showitemsdialog.h"
#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"
#include "../../Appointment/display/displayappointmentwid.h"

class DisplayDrugWid : public QWidget
{
    Q_OBJECT
    QGridLayout *lay;
    QLabel *name_l,*name_e,*date_l,*date_e,*duration_l,*duration_e;
    QPushButton *app_b;
    Drug *model;
    QString path;
    QString to_open;
public:
    explicit DisplayDrugWid(Drug *arg,QWidget *parent=0);
    
signals:
    
public slots:
    void displayLinks();
    void displayAppointment();
    
};

#endif // DISPLAYDRUGWID_H
