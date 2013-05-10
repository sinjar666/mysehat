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

#include "editfamilyhistorywid.h"

EditFamilyHistoryWid::EditFamilyHistoryWid(QString path_a, IndexItem olditem, QWidget *parent) :
    QWidget(parent)
{
    path=path_a;
    old_item=olditem;
    model = new FamilyHistory();
    xml = new XFamilyHistory(model,old_item.getLocation());
    xml->readData();
    lay=new QGridLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit(model->getName());
    mother_e = new QCheckBox(tr("Mother"));
    father_e = new QCheckBox(tr("Father"));
    brother_e = new QCheckBox(tr("Brother"));
    sister_e = new QCheckBox(tr("Sister"));
    grandfather_e = new QCheckBox(tr("GrandFather"));
    grandmother_e = new QCheckBox(tr("GrandMother"));
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    brother_e->setChecked(model->isBrother());
    mother_e->setChecked(model->isMother());
    father_e->setChecked(model->isFather());
    sister_e->setChecked(model->isSister());
    grandfather_e->setChecked(model->isGrandfather());
    grandmother_e->setChecked(model->isGrandmother());
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(mother_e,1,0);
    lay->addWidget(father_e,1,1);
    lay->addWidget(brother_e,2,0);
    lay->addWidget(sister_e,2,1);
    lay->addWidget(grandfather_e,3,0);
    lay->addWidget(grandmother_e,3,1);
    lay->addWidget(save_b,4,0);
    lay->addWidget(reset_b,4,1);
    connect(save_b,SIGNAL(clicked()),this,SLOT(performSave()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(performReset()));
}

void EditFamilyHistoryWid::performReset()   {
    mother_e->setChecked(false);
    father_e->setChecked(false);
    sister_e->setChecked(false);
    brother_e->setChecked(false);
    grandfather_e->setChecked(false);
    grandmother_e->setChecked(false);
    name_e->clear();
}

void EditFamilyHistoryWid::performSave()    {
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
    model->setMembers(0);
    if(mother_e->isChecked())
        model->addMember(FamilyHistory::MOTHER_T);
    if(father_e->isChecked())
        model->addMember(FamilyHistory::FATHER_T);
    if(brother_e->isChecked())
        model->addMember(FamilyHistory::BROTHER_T);
    if(sister_e->isChecked())
        model->addMember(FamilyHistory::SISTER_T);
    if(grandfather_e->isChecked())
        model->addMember(FamilyHistory::GRANDFATHER_T);
    if(grandmother_e->isChecked())
        model->addMember(FamilyHistory::GRANDMOTHER_T);
    xml->saveData();
    IndexItem item(old_item.getDate(),old_item.getLocation(),6,old_item.getDisease());
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
