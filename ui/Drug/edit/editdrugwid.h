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

#ifndef EDITDRUGWID_H
#define EDITDRUGWID_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QDateEdit>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>

#include "model/drug.h"
#include "xml/Drug/xdrug.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "KeyFinder/keyfinder.h"

class EditDrugWid : public QWidget
{
    Q_OBJECT
    QLabel *name_l,*date_l,*duration_l;
    QLineEdit *name_e;
    QDateEdit *date_e;
    QSpinBox *duration_e;
    QGridLayout *lay;
    QPushButton *save_b,*reset_b;
    QString path;
    IndexItem old_item;
    Drug *model;
    XDrug *xml;

public:
    explicit EditDrugWid(QString path_a,IndexItem olditem,QWidget *parent = 0);
    
signals:
    
public slots:
    void performReset();
    void performSave();
    
};

#endif // EDITDRUGWID_H
