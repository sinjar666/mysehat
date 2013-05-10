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

#include "appointmentlist.h"

AppointmentList::AppointmentList(
    QList<AppointmentButton *> list_a,QWidget *parent) :
    QWidget(parent)
{
    v_layout = new QVBoxLayout(this);
    addButtons(list_a);
}

void AppointmentList::addButtons(QList<AppointmentButton *> list)
{
    AppointmentButton *i;
    if(list.length()==0)
    {
        QLabel *app_label=new QLabel("<font size=\"7\">No appointments found</font>");
        v_layout->addWidget(app_label);
    }
    else
    {
        QLabel *app_label=new QLabel("<font size=\"5\">List of Appointments<font>");
        v_layout->addWidget(app_label);
        foreach(i,list)
        {
            v_layout->addWidget(i);
        }
    }
}
