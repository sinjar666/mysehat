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

#ifndef SHOWITEMSDIALOG_H
#define SHOWITEMSDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QLabel>
#include "search-engine/engine/engine.h"
#include "xml/Symptom/xsymptom.h"
#include "xml/Surgery/xsurgery.h"
#include "xml/Drug/xdrug.h"
#include "xml/Investigation/xinvestigation.h"
#include "xml/Appointment/xappointment.h"
#include "model/appointment.h"
#include "model/drug.h"
#include "model/investigation.h"
#include "model/surgery.h"
#include "model/symptom.h"

class ShowItemsDialog : public QDialog
{
    Q_OBJECT
    QVBoxLayout *lay;
    QListWidget *view;
    QString *val;
    Engine::Filters type;
    QList<QString> items;
public:
    explicit ShowItemsDialog(Engine::Filters arg,QList<QString> items_arg,QString *val_a,QWidget *parent = 0);
    
signals:
    
public slots:
    void onItemDoubleClicked(QListWidgetItem *item);
    
};

#endif // SHOWITEMSDIALOG_H
