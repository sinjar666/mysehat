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

#include "displayallergenwid.h"

DisplayAllergenWid::DisplayAllergenWid(Allergen *arg, QWidget *parent) :
    QWidget(parent)
{
    model = arg;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLabel(model->getName());
    type_l = new QLabel(tr("Type"));
    QStringList types;
    types << "Drug" << "Natural" << "Synthetic" << "Food";
    type_e = new QLabel(types[(int)model->getType()]);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(type_l,1,0);
    lay->addWidget(type_e,1,1);
}
