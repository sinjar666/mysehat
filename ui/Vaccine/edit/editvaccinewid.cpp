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

#include "editvaccinewid.h"

EditVaccineWid::EditVaccineWid(QString path_a, IndexItem olditem, QWidget *parent) :
    QWidget(parent)
{
    path=path_a;
    old_item = olditem;
    model = new Vaccine();
    xml = new XVaccine(model,olditem.getLocation());
    xml->readData();
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit(model->getName());
    date_l = new QLabel(tr("Date"));
    date_e = new QDateEdit(model->getDate());
    validity_l = new QLabel(tr("Validity"));
    validity_e = new QSpinBox();
    validity_e->setValue(model->getValidity());
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QGridLayout(this);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(validity_l,2,0);
    lay->addWidget(validity_e,2,1);
    lay->addWidget(save_b,3,0);
    lay->addWidget(reset_b,3,1);
    connect(save_b,SIGNAL(clicked()),this,SLOT(performSave()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(performReset()));
}

void EditVaccineWid::performReset() {
    name_e->clear();
    date_e->setDate(QDate::currentDate());
    validity_e->setValue(0);
}

void EditVaccineWid::performSave()  {
    if(name_e->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the disease"));

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
    model->setValidity(validity_e->value());
    xml->saveData();
    IndexItem item(date_e->date(),old_item.getLocation(),7,old_item.getDisease());
    keyfinder = new KeyFinder(model->getName());
    keys=keyfinder->generate();
    foreach(key,keys)   {
        engine->addEntry(key,item);
    }
    engine->saveIndex();
    xml->deleteLater();
    engine->deleteLater();
    keyfinder->deleteLater();
    model->deleteLater();
    close();
    }
}
