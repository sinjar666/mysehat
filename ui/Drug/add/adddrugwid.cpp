/***************************************************************************************
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

#include "adddrugwid.h"

AddDrugWid::AddDrugWid(QString rootdir, QWidget *parent) :
    QWidget(parent)
{
    path=rootdir;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit();
    date_l = new QLabel(tr("Date prescribed"));
    date_e = new QDateEdit(QDate::currentDate());
    duration_l = new QLabel(tr("Duration(days)"));
    duration_e = new QSpinBox();
    duration_e->setMinimum(0);
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(duration_l,2,0);
    lay->addWidget(duration_e,2,1);
    lay->addWidget(save_b,3,0);
    lay->addWidget(reset_b,3,1);
    connect(save_b,SIGNAL(clicked()),this,SLOT(performSave()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(performReset()));
}

void AddDrugWid::performReset() {
    name_e->clear();
    date_e->setDate(QDate::currentDate());
    duration_e->setValue(0);
}

void AddDrugWid::performSave()  {
    if(name_e->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the drug"));
    }
    else
    {
    Drug *model = new Drug();
    IdGen *id_gen = new IdGen(path);
    QString id = id_gen->generate(IdGen::DRUG_T);
    model->setName(name_e->text());
    model->setDate(date_e->date());
    model->setDuration((quint16)duration_e->value());
    XDrug *xml = new XDrug(model,id);
    xml->saveData();
    IndexItem index_item(date_e->date(),id,3,QString(""));
    Engine *engine = new Engine(path+"/");
    engine->loadIndex();
    QStringList keys;
    KeyFinder *finder = new KeyFinder(name_e->text());
    keys = finder->generate();
    QString key;
    foreach(key,keys)   {
        engine->addEntry(key,index_item);
    }
    engine->saveIndex();
    model->deleteLater();
    id_gen->deleteLater();
    xml->deleteLater();
    engine->deleteLater();
    finder->deleteLater();

    close();
    }
}
