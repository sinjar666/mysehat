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

#ifndef EDITALLERGENWID_H
#define EDITALLERGENWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QErrorMessage>

#include "editbottom.h"
#include "editmiddle.h"
#include "editupper.h"
#include "IdGen/idgen.h" //generates Id
#include "KeyFinder/keyfinder.h" //generates keywords
#include "model/allergen.h"
#include "xml/Allergen/xallergen.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"

class EditAllergenWid : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout;
    EditUpper *u;
    EditMiddle *m;
    EditBottom *b;

    Allergen *model;

    QString path,old;
    IndexItem old_item;
public:
    explicit EditAllergenWid(QString rootdir,IndexItem olditem_a,QWidget *parent);

    
signals:
    
public slots:
    void performReset(); //to clear all the fields
    void performSave(); //to save the file
};

#endif // ADDALLERGENWID_H
