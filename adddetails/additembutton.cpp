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

#include "additembutton.h"

AddItemButton::AddItemButton(ItemType type, QWidget *parent) :
    QPushButton(parent)
{
    //setMinimumSize(200,200);

    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    names << "Appointment" << "Symptom" << "Investigation" << "Surgery" << "Drug" << "Allergen" << "Vaccine" << "Family History";
    iconpaths << ":/icons/appointment.jpg" << ":/icons/symptom.xpm" << ":/icons/investigation.xpm"
              << ":/icons/surgery.xpm" << ":/icons/drug.xpm" << ":/icons/allergen.xpm" << ":/icons/vaccine.xpm"
              << ":/icons/family.xpm";
    lay = new QVBoxLayout(this);
    icon_l = new QLabel();
    icon_l->setPixmap(QPixmap::fromImage(QImage(iconpaths[(int)type])).scaled(150,150));
    name_l = new QLabel(names[(int)type]);
    lay->addWidget(icon_l);
    lay->addWidget(name_l);
}
