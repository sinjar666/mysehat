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

#include "typedatewid.h"

TypeDateWid::TypeDateWid(QString type, QDate date,QString disease,QWidget *parent) :
    QWidget(parent)
{
    QString str;
    str="<font color='red'>"+disease+"</font>"+"     "+"<font color='yellow'>"+type+"</font>";
    type_l = new QLabel(str);
    type_l->setTextFormat(Qt::RichText);
    date_l = new QLabel(date.toString());
    date_l->setAlignment(Qt::AlignRight);
    layout = new QHBoxLayout(this);
    layout->addWidget(type_l);
    layout->addWidget(date_l);
    //setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}
