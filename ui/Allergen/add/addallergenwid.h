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

#ifndef ADDALLERGENWID_H
#define ADDALLERGENWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QErrorMessage>

#include "bottom.h"
#include "middle.h"
#include "upper.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "model/allergen.h"
#include "xml/Allergen/xallergen.h"
#include "search-engine/engine/engine.h"

class AddAllergenWid : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout;
    upper *u;
    Middle *m;
    bottom *b;

    QString path;
public:
    explicit AddAllergenWid(QString rootdir,QWidget *parent = 0);

    
signals:
    
public slots:
    void performReset(); //to clear all the fields
    void performSave(); //to save the file
};

#endif // ADDALLERGENWID_H
