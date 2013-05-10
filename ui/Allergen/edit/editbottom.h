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

#ifndef EDITBOTTOM_H
#define EDITBOTTOM_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class EditBottom : public QWidget
{
    QPushButton *button1,*button2;
    QHBoxLayout *h;
    Q_OBJECT
public:
    explicit EditBottom(QWidget *parent = 0);

signals:
    void resetPressed();
    void savePressed();

public slots:
    void onReset();
    void onSave();

};

#endif // BOTTOM_H
