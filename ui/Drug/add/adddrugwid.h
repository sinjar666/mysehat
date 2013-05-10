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

#ifndef ADDDRUGWID_H
#define ADDDRUGWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QErrorMessage>

#include "model/drug.h"
#include "xml/Drug/xdrug.h"
#include "config/config.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"

class AddDrugWid : public QWidget
{
    Q_OBJECT
    QString path;
    QLabel *name_l,*date_l,*duration_l;
    QDateEdit *date_e;
    QLineEdit *name_e;
    QGridLayout *lay;
    QSpinBox *duration_e;
    QPushButton *save_b,*reset_b;


public:
    explicit AddDrugWid(QString rootdir,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // ADDDRUGWID_H
