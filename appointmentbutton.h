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

#ifndef APPOINTMENTBUTTON_H
#define APPOINTMENTBUTTON_H

#include <QPushButton>
#include <QSize>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>

#include "model/appointment.h"
#include "xml/Appointment/xappointment.h"

class AppointmentButton : public QPushButton
{
    Q_OBJECT
    QString path;
    QHBoxLayout *h_layout;
    QDate date_value;
    QString doc_name;
    QLabel *date_l,*docname_l;
    Appointment *model;
    XAppointment *xappoint;

public:
    explicit AppointmentButton(QString path_a,QWidget *parent = 0);
    QSize sizeHint() const;

signals:
    void AppointItemClicked(QString);

public slots:
    void appointClicked();

};

#endif // APPOINTMENTBUTTON_H
