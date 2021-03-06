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

#ifndef ADDSYMPTOMWID_H
#define ADDSYMPTOMWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QDate>
#include <QErrorMessage>

#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "xml/Symptom/xsymptom.h"
#include "model/symptom.h"

class AddSymptomWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    QLabel *desc,*char_l;
    QTextEdit *details;
    QLineEdit *charac;
    QString path;
    QPushButton *save,*reset;
    Symptom *model;

public:
    explicit AddSymptomWid(QString rootdir,QWidget *parent = 0);

signals:

public slots:
    void perform_save();
    void reset_function();
};

#endif // ADDSYMPTOMWID_H
