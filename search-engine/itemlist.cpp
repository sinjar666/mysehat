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

#include "itemlist.h"

ItemList::ItemList(QString uroot_a,Engine *arg, QWidget *parent) :
    QWidget(parent)
{
    uroot=uroot_a;
    engine=arg;
    lay = new QVBoxLayout(this);
    setLayout(lay);
    //performSearch(QString());
}
ItemList::ItemList(QString uroot_a,Engine *arg, QList<ItemButton *> l, QWidget *parent):
    QWidget(parent)
{
    uroot=uroot_a;
    engine=arg;
    lay=new QVBoxLayout(this);
    addButtons(l);
}


void ItemList::addButtons(QList<ItemButton *> l)    {
    ItemButton *i;
    foreach(i,l)    {
        lay->addWidget(i);
        connect(i,SIGNAL(triggerOpen(QString,ItemButton::ItemType)),this,SLOT(sendTrigger(QString,ItemButton::ItemType)));
        connect(i,SIGNAL(triggerEdit(IndexItem)),this,SLOT(sendTrigger2(IndexItem)));
        connect(i,SIGNAL(triggerDisease(IndexItem)),this,SLOT(sendTrigger3(IndexItem)));
        connect(i,SIGNAL(triggerDelete(IndexItem,ItemButton *)),this,SLOT(sendTrigger4(IndexItem,ItemButton *)));
    }
}

void ItemList::sendTrigger(QString loc, ItemButton::ItemType type)  {
    emit triggerOpen(loc,type);
}

void ItemList::sendTrigger2(IndexItem item) {
    emit triggerEdit(item);
}

void ItemList::sendTrigger3(IndexItem item) {
    emit triggerDisease(item);
}

void ItemList::sendTrigger4(IndexItem item, ItemButton *obj) {
    emit triggerDelete(item,obj);
}
