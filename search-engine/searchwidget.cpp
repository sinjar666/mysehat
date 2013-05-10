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
#include "searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent) :
    QWidget(parent)
{
    key_e = new QLineEdit();

    searchButton = new QPushButton();
    filterButton = new QPushButton("filter...");
    QImage temp(":/icons/Search.png");
    searchButton->setIcon(QIcon(QPixmap::fromImage(temp).scaled(20,20)));
    layout = new QHBoxLayout(this);
    layout->addWidget(key_e);
    layout->addWidget(filterButton);
    layout->addWidget(searchButton);
    connect(searchButton,SIGNAL(clicked()),this,SLOT(buttonPressed()));
    connect(key_e,SIGNAL(returnPressed()),this,SLOT(buttonPressed()));
    connect(filterButton,SIGNAL(clicked()),this,SLOT(filterPressed()));
}

void SearchWidget::buttonPressed()  {
    emit searchPressed();
}

QString SearchWidget::getKey()  {
    return key_e->text();
}

void SearchWidget::filterPressed()  {
    emit filter();
}
