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

#include "vaccinebottomwid.h"

VaccineBottomWid::VaccineBottomWid(QWidget *parent) :
    QWidget(parent)
{
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QHBoxLayout(this);
    lay->addWidget(save_b);
    lay->addWidget(reset_b);
    connect(save_b,SIGNAL(clicked()),this,SLOT(onSavePressed()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(onResetPressed()));
}

void VaccineBottomWid::onResetPressed() {
    emit sendReset();
}

void VaccineBottomWid::onSavePressed()  {
    emit sendSave();
}
