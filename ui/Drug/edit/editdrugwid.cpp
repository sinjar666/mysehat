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

#include "editdrugwid.h"

EditDrugWid::EditDrugWid(QString path_a, IndexItem olditem, QWidget *parent) :
    QWidget(parent)
{
    path=path_a;
    old_item=olditem;
    model = new Drug();
    xml = new XDrug(model,old_item.getLocation());
    xml->readData();
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit(model->getName());
    date_l = new QLabel(tr("Date"));
    date_e = new QDateEdit(model->getDate());
    duration_l = new QLabel(tr("Duration"));
    duration_e = new QSpinBox();
    duration_e->setValue(model->getDuration());
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QGridLayout(this);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(duration_l,2,0);
    lay->addWidget(duration_e,2,2);
    lay->addWidget(save_b,3,0);
    lay->addWidget(reset_b,3,1);
    connect(save_b,SIGNAL(clicked()),this,SLOT(performSave()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(performReset()));
}

void EditDrugWid::performReset()    {
    name_e->clear();
    date_e->setDate(QDate::currentDate());
    duration_e->setValue(0);
}

void EditDrugWid::performSave() {
    if(name_e->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the drug"));
    }
    else
    {
    Engine *engine = new Engine(path);
    engine->loadIndex();
    QStringList keys;
    QString key;
    KeyFinder *keyfinder = new KeyFinder(model->getName());
    keys = keyfinder->generate();
    foreach(key,keys)   {
        engine->remove(key,old_item);
    }
    keyfinder->deleteLater();

    model->setName(name_e->text());
    model->setDate(date_e->date());
    model->setDuration(duration_e->value());
    xml->saveData();
    IndexItem item(date_e->date(),old_item.getLocation(),3,old_item.getDisease());
    keyfinder = new KeyFinder(model->getName());
    keys=keyfinder->generate();
    foreach(key,keys)   {
        engine->addEntry(key,item);
    }
    engine->saveIndex();
    xml->deleteLater();
    engine->deleteLater();
    keyfinder->deleteLater();
    close();
    }
}
