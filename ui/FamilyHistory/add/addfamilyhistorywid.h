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

#ifndef ADDFAMILYHISTORYWID_H
#define ADDFAMILYHISTORYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QErrorMessage>

#include "model/familyhistory.h"
#include "xml/FamilyHistory/xfamilyhistory.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "config/config.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"

class AddFamilyHistoryWid : public QWidget
{
    Q_OBJECT
    QString path;
    QGridLayout *lay;
    QLabel *name_l;
    QLineEdit *name_e;
    QCheckBox *mother_e,*father_e,*brother_e,*sister_e,*grandfather_e,*grandmother_e;
    QPushButton *save_b,*reset_b;
public:
    explicit AddFamilyHistoryWid(QString rootdir,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // ADDFAMILYHISTORYWID_H
