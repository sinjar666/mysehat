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

#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QDebug>
#include <QErrorMessage>

#include "config/config.h"
#include "search-engine/engine/engine.h"
#include "passman/passman.h"

class NewUserDialog : public QDialog
{
    Q_OBJECT
    QLabel *newuser_l,*pass_l;
    QLineEdit *newuser_e,*pass_e;
    QPushButton *button;
    QGridLayout *glayout;
    QDir *pathdir;

public:
    explicit NewUserDialog(QDir *pathdir_a,QWidget *parent = 0);

signals:
    void username(QString username);

public slots:
    void config_user();

};

#endif // NEWUSERDIALOG_H
