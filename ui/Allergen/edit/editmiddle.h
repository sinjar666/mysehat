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

#ifndef EDITMIDDLE_H
#define EDITMIDDLE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QString>
#include "model/allergen.h"


class EditMiddle : public QWidget
{
    Q_OBJECT
    QComboBox *box;
    QStringList *types;
    QLabel *label1;
    QHBoxLayout *h;
public:
    explicit EditMiddle(QWidget *parent = 0);
    Allergen::A_type getType(); //used to obtain the type
    //note the return type of the above function is exactly same
    //as the argument to be given to the setType function in the model
    //hence the model header has been included so that we can access this type
    void setType(Allergen::A_type type);
signals:

public slots:

};

#endif // MIDDLE_H
