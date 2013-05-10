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

#include "displayvaccinewid.h"

DisplayVaccineWid::DisplayVaccineWid(Vaccine *arg, QWidget *parent) :
    QWidget(parent)
{
    model = arg;
    lay =new QGridLayout(this);
    name_l = new QLabel(tr("Name of Vaccine:"));
    name_e = new QLabel(model->getName());
    validity_l = new QLabel(tr("Validity"));
    validity_e = new QLabel(QString::number(model->getValidity()));
    date_l = new QLabel(tr("Date:"));
    date_e = new QLabel(model->getDate().toString());
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(validity_l,1,0);
    lay->addWidget(validity_e,1,1);
    lay->addWidget(date_l,2,0);
    lay->addWidget(date_e,2,1);
}
