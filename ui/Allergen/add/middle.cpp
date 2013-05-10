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

#include "middle.h"

Middle::Middle(QWidget *parent) :
    QWidget(parent)
{
    label1=new QLabel("Type");
    box=new QComboBox();
    types = new QStringList();
    *types <<"Drug" <<"Natural" <<"Synthetic" <<"Food" ;
    box->addItems(*types);
    h=new QHBoxLayout(this);
    h->addWidget(label1);
    h->addWidget(box);
}

Allergen::A_type Middle::getType()  {
    switch(box->currentIndex())  {
    case 0:
        return Allergen::drug_t;
    case 1:
        return Allergen::natural_t;
    case 2:
        return Allergen::synthetic_t;
    case 3:
        return Allergen::food_t;
    }

}
