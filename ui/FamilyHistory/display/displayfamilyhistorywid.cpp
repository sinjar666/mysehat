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

#include "displayfamilyhistorywid.h"

DisplayFamilyHistoryWid::DisplayFamilyHistoryWid(FamilyHistory *arg, QWidget *parent) :
    QWidget(parent)
{
    model=arg;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Name of Disease:"));
    name_e = new QLabel(model->getName());
    members_l = new QLabel(tr("Members:"));

    QString txt;
    if(model->isBrother()) txt+="Brother\n";
    if(model->isFather()) txt+="Father\n";
    if(model->isGrandfather()) txt += "Grandfather\n";
    if(model->isGrandmother()) txt += "Grandmother\n";
    if(model->isMother()) txt += "Mother\n";
    if(model->isSister()) txt += "Sister";
    members_e = new QLabel(txt);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(members_l,1,0);
    lay->addWidget(members_e,1,1);
}
