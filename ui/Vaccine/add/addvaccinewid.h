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

#ifndef ADDVACCINEWID_H
#define ADDVACCINEWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QErrorMessage>

#include "vaccinebottomwid.h"
#include "vaccinedetailswid.h"
#include "model/vaccine.h"
#include "xml/Vaccine/xvaccine.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"

class AddVaccineWid : public QWidget
{
    Q_OBJECT
    VaccineDetailsWid *det_w;
    VaccineBottomWid *bottom;
    QVBoxLayout *lay;
    QString path;
public:
    explicit AddVaccineWid(QString rootdir, QWidget *parent=0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // ADDVACCINEWID_H
