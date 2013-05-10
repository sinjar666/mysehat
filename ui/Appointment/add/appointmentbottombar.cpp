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

#include "appointmentbottombar.h"

AppointmentBottomBar::AppointmentBottomBar(QWidget *parent) :
    QWidget(parent)
{
    add_b = new QPushButton(tr("Add"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QHBoxLayout(this);
    lay->addWidget(add_b);
    lay->addWidget(reset_b);
    connect(reset_b,SIGNAL(clicked()),this,SLOT(onResetPressed()));
    connect(add_b,SIGNAL(clicked()),this,SLOT(onAddPressed()));
}

void AppointmentBottomBar::onResetPressed() {
    emit sendReset();
}

void AppointmentBottomBar::onAddPressed()   {
    emit sendAdd();
}
