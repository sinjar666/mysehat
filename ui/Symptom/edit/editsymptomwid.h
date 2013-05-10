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

#ifndef EDITSYMPTOMWID_H
#define EDITSYMPTOMWID_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QTextEdit>
#include <QLineEdit>
#include <QErrorMessage>

#include "model/symptom.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "xml/Symptom/xsymptom.h"
#include "KeyFinder/keyfinder.h"

class EditSymptomWid : public QWidget
{
    Q_OBJECT
    IndexItem old_item;
    QGridLayout *g_layout;
    QString path;
    Symptom *model;
    XSymptom *xml;
    QLineEdit *charac;
    QTextEdit *desc;
    QPushButton *save_b,*reset_b;
    QLabel *details_l,*charac_l;

public:
    explicit EditSymptomWid(QString path_a,IndexItem olditem,QWidget *parent = 0);

signals:

public slots:
    void perform_save();
    void perform_reset();

};

#endif // EDITSYMPTOMWID_H
