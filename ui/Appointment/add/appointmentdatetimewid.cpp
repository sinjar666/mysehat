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

#include "appointmentdatetimewid.h"

AppointmentDateTimeWid::AppointmentDateTimeWid(QWidget *parent) :
    QWidget(parent)
{
    datetime_e = new QDateTimeEdit();
    datetime_e->setDateTime(QDateTime::currentDateTime());
    datetime_l = new QLabel(tr("Date/Time"));
    lay = new QHBoxLayout(this);
    lay->addWidget(datetime_l);
    lay->addWidget(datetime_e);
}

void AppointmentDateTimeWid::resetAll() {
    datetime_e->setDate(QDate::currentDate());
    datetime_e->setTime(QTime::currentTime());
}

QDate AppointmentDateTimeWid::getDate() {
    return datetime_e->date();
}

QTime AppointmentDateTimeWid::getTime() {
    return datetime_e->time();
}
