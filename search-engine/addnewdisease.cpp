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

#include "addnewdisease.h"

AddNewDisease::AddNewDisease(QString *name_a,QWidget *parent) :
    QDialog(parent)
{
    name = name_a;
    setModal(true);
    lay = new QHBoxLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit();
    add_b = new QPushButton(tr("Add"));
    lay->addWidget(name_l);
    lay->addWidget(name_e);
    lay->addWidget(add_b);
    connect(add_b,SIGNAL(clicked()),this,SLOT(performAdd()));
}

void AddNewDisease::performAdd()    {
    *name = name_e->text();
    accept();
}
