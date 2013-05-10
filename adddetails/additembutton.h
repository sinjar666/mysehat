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

#ifndef ADDITEMBUTTON_H
#define ADDITEMBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QImage>

class AddItemButton : public QPushButton
{
    Q_OBJECT
    QVBoxLayout *lay;
    QLabel *icon_l,*name_l;
    QStringList names,iconpaths;
public:
    typedef enum    {
        APPOINTMENT_T = 0,
        SYMPTOM_T = 1,
        INVESTIGATION_T = 2,
        SURGERY_T = 3,
        DRUG_T = 4,
        ALLERGEN_T=5,
        VACCINE_T=6,
        FAMILYHISTORY_T=7
    } ItemType;

    explicit AddItemButton(ItemType type,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ADDITEMBUTTON_H
