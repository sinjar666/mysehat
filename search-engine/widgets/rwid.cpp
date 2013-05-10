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

#include "rwid.h"

RWid::RWid(QString descr,QString type,QDate date,QString disease,QWidget *parent) :
    QWidget(parent)
{
    QString str = descr.left(20);
    str = str + "...";
    descr_e = new QLabel(str);
    //descr_e->setReadOnly(true);
    w = new TypeDateWid(type,date,disease);
    layout = new QVBoxLayout(this);
    layout->addWidget(descr_e);
    layout->addWidget(w);
    //setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}

QSize RWid::sizeHint() const    {
    return(QSize(725,100));
}
