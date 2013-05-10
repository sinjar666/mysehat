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

#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QWidget>
#include <QGroupBox>
#include "engine/indexitem.h"
#include "engine/engine.h"
#include "itembutton.h"

class ItemList : public QWidget
{
    Q_OBJECT
    QVBoxLayout *lay;
    QGroupBox *box;
    Engine *engine;
    QString uroot;
    //ItemButton *temp;
public:
    explicit ItemList(QString uroot_a,Engine *arg,QWidget *parent = 0);
    ItemList(QString uroot_a,Engine *arg,QList<ItemButton *>l,QWidget *parent=0);
    void addButtons(QList<ItemButton *> l);
    //QSize sizeHint();

signals:
    void triggerOpen(QString, ItemButton::ItemType);
    void triggerEdit(IndexItem);
    void triggerDisease(IndexItem);
    void triggerDelete(IndexItem,ItemButton *);

public slots:
    void sendTrigger(QString loc,ItemButton::ItemType type);
    void sendTrigger2(IndexItem item);
    void sendTrigger3(IndexItem item);
    void sendTrigger4(IndexItem item,ItemButton *);

};


#endif // ITEMLIST_H
