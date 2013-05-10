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

#ifndef DIALOGRIGHT_H
#define DIALOGRIGHT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class DialogRight : public QWidget
{
    Q_OBJECT
    QVBoxLayout *lay;
    QPushButton *new_b,*choose_b;
    QString name;

public:
    explicit DialogRight(QWidget *parent=0);
    
signals:
    void choosePressed();
    void newPressed();
    
public slots:
    void onChoose();
    void onNew();
    
};

#endif // DIALOGRIGHT_H
