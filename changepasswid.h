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

#ifndef CHANGEPASSWID_H
#define CHANGEPASSWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QErrorMessage>
#include <QString>

#include "passman/passman.h"

class ChangePassWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    QLabel *old_l,*new_l,*retype_l;
    QPushButton *ok_button;
    QLineEdit *old_e,*new_e,*retype_e;
    QString curr_user;
public:
    explicit ChangePassWid(QString currentuser,QWidget *parent = 0);
    
signals:
    
public slots:
    void passauth();
    
};

#endif // CHANGEPASSWID_H
