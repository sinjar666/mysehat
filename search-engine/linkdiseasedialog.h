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

#ifndef LINKDISEASEDIALOG_H
#define LINKDISEASEDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include "dialogright.h"
#include "xdisease/xdisease.h"
#include "addnewdisease.h"

class LinkDiseaseDialog : public QDialog
{
    Q_OBJECT
    QListWidget *disease_list;
    QHBoxLayout *lay;
    DialogRight *right_w;
    QString *disease,loc,uroot;
    AddNewDisease *new_dialog;
    QString name;
public:
    explicit LinkDiseaseDialog(QString uroot_a,QString *arg,QString loc_a,QWidget *parent = 0);
    void populate();
    
signals:
    
public slots:
    void addNew();
    void itemChosen();
    
};

#endif // LINKDISEASEDIALOG_H
