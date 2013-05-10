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

#ifndef EDITSURGERYWID_H
#define EDITSURGERYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QErrorMessage>

#include "model/surgery.h"
#include "KeyFinder/keyfinder.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "xml/Surgery/xsurgery.h"

class EditSurgeryWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    QDateEdit *date_e;
    QString path;
    IndexItem old_item;
    Surgery *model;
    XSurgery *xml;
    QLabel *date_l,*detail_l;
    QTextEdit *detail_e;
    QPushButton *save_b,*reset_b;
public:
    explicit EditSurgeryWid(QString path_a,IndexItem olditem,QWidget *parent = 0);

signals:

public slots:
    void perform_save();
    void perform_reset();
};

#endif // EDITSURGERYWID_H
