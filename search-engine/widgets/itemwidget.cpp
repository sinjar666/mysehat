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

#include "itemwidget.h"

ItemWidget::ItemWidget(const QPixmap img, QString descr, QString type, QDate date,QString disease,QWidget *parent) :
    QWidget(parent)
{
    QPixmap scaledImg = img.scaled(100,100);
    icon = new QLabel();
    icon->setPixmap(scaledImg);
    w = new RWid(descr,type,date,disease);
    layout = new QHBoxLayout(this);
    layout->addWidget(icon);
    layout->addWidget(w);
    //setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}
QSize ItemWidget::sizeHint() const  {
    return(QSize(790,100));
}
