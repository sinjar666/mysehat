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

#include "linkdiseasedialog.h"

LinkDiseaseDialog::LinkDiseaseDialog(QString uroot_a, QString *arg, QString loc_a, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    uroot=uroot_a;
    loc=loc_a;
    disease=arg;
    setModal(false);
    setAttribute(Qt::WA_DeleteOnClose);
    lay = new QHBoxLayout(this);
    disease_list = new QListWidget();
    right_w = new DialogRight();
    populate();
    lay->addWidget(disease_list);
    lay->addWidget(right_w);
    new_dialog = new AddNewDisease(&name,this);
    connect(right_w,SIGNAL(newPressed()),this,SLOT(addNew()));
    connect(right_w,SIGNAL(choosePressed()),this,SLOT(itemChosen()));
}

void LinkDiseaseDialog::populate()  {
    //Read file and populate the list
    XDisease *obj;
    obj = new XDisease(uroot);
    QStringList diseases = obj->getdname();
    disease_list->clear();
    disease_list->addItems(diseases);
    obj->deleteLater();
}

void LinkDiseaseDialog::addNew()    {
    if(new_dialog->exec())  {
        disease_list->insertItem(0,name);
        disease_list->setCurrentRow(0);
    }
}

void LinkDiseaseDialog::itemChosen()    {
    *disease=disease_list->currentItem()->text();
    XDisease *obj = new XDisease(uroot);
    obj->adddisease(*disease,loc);
    obj->deleteLater();
   // qDebug()<<*disease;
    accept();
}
