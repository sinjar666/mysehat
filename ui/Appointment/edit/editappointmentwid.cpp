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

#include "editappointmentwid.h"

EditAppointmentWid::EditAppointmentWid(QString path_a, IndexItem olditem, QWidget *parent):
    QWidget(parent)
{
    path=path_a;
    old_item=olditem;
    model = new Appointment();
    XAppointment *xml = new XAppointment(model,olditem.getLocation());
    xml->readData();
    syms = model->getSymptom();
    drug = model->getDrug();
    sur = model->getSurgery();
    inv = model->getInvestigation();
    name_l = new QLabel(tr("Name of Doctor"));
    name_e = new QLineEdit(model->getName());
    date_l = new QLabel(tr("Date"));
    date_e = new QDateEdit(model->getDate());
    time_l = new QLabel(tr("Time"));
    time_e = new QTimeEdit(model->getTime());
    category_l = new QLabel(tr("Category"));
    category_e = new QComboBox();
    QStringList category;
    category << "Symptom" << "Drug" << "Surgery" << "Investigation";
    category_e->addItems(category);
    viewLinks = new QPushButton(tr("View/Delete Links"));
    addLinks = new QPushButton(tr("Add Links"));
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QGridLayout(this);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(time_l,2,0);
    lay->addWidget(time_e,2,1);
    lay->addWidget(category_l,3,0);
    lay->addWidget(category_e,3,1);
    lay->addWidget(viewLinks,4,0);
    lay->addWidget(addLinks,4,1);
    lay->addWidget(save_b,5,0);
    lay->addWidget(reset_b,5,1);
    connect(viewLinks,SIGNAL(clicked()),this,SLOT(onViewLinks()));
    connect(addLinks,SIGNAL(clicked()),this,SLOT(onAddLinks()));
    connect(save_b,SIGNAL(clicked()),this,SLOT(performSave()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(performReset()));
}

void EditAppointmentWid::onAddLinks()   {
    SearchDialog *sd;
    switch(category_e->currentIndex())  {

    case 0:
        sd = new SearchDialog(path+"/",Engine::SYMPTOM_F,model,this);
        break;
    case 1:
        sd = new SearchDialog(path+ "/",Engine::DRUG_F,model,this);
        break;

    case 2:
        sd = new SearchDialog(path+"/",Engine::SURGERY_F,model,this);
        break;
    case 3:
        sd = new SearchDialog(path+"/",Engine::INVESTIGATION_F,model,this);
        break;
    default:
        qDebug("Not possible");
    }
    sd->exec();
}

void EditAppointmentWid::onViewLinks()  {
    EditLinksDialog *ld;
    switch(category_e->currentIndex())  {
    case 0: {
        ld = new EditLinksDialog(old_item.getLocation(),model,Engine::SYMPTOM_F,this);
        ld->exec();
        break;
    }
    case 1: {
        ld = new EditLinksDialog(old_item.getLocation(),model,Engine::DRUG_F,this);
        ld->exec();
        break;
    }
    case 2: {
        ld = new EditLinksDialog(old_item.getLocation(),model,Engine::SURGERY_F,this);
        ld->exec();
        break;
    }
    case 3: {
        ld = new EditLinksDialog(old_item.getLocation(),model,Engine::INVESTIGATION_F,this);
        ld->exec();
        break;
    }
    }
}

void EditAppointmentWid::performReset() {
    name_e->clear();
    date_e->setDate(QDate::currentDate());
    time_e->setTime(QTime::currentTime());
}

void EditAppointmentWid::performSave()  {
    if(name_e->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the doctor"));
        //mesg->deleteLater();
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
    model->setTime(time_e->time());

    /*Remove the back links in the old files*/
    symptomComplained sym_l;
    drugPrescribed dr_l;
    surgeryAdvised sur_l;
    investigationAdvised inv_l;

    foreach(sym_l,syms) {
        Symptom *model_t = new Symptom();
        XSymptom *xml_t = new XSymptom(model_t,sym_l.link);
        xml_t->readData();
        model_t->removeLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(inv_l,inv) {
        Investigation *model_t = new Investigation();
        XInvestigation *xml_t = new XInvestigation(model_t,inv_l.link);
        xml_t->readData();
        model_t->removeLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(dr_l,drug) {
        Drug *model_t = new Drug();
        XDrug *xml_t = new XDrug(model_t,dr_l.link);
        xml_t->readData();
        model_t->removeLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(sur_l,sur) {
        Surgery *model_t = new Surgery();
        XSurgery *xml_t = new XSurgery(model_t,sur_l.link);
        xml_t->readData();
        model_t->removeLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }

    //Obtain list of new files from model
    syms = model->getSymptom();
    drug = model->getDrug();
    sur = model->getSurgery();
    inv = model->getInvestigation();

    //Add the back links in the new files
    foreach(sym_l,syms) {
        Symptom *model_t = new Symptom();
        XSymptom *xml_t = new XSymptom(model_t,sym_l.link);
        xml_t->readData();
        model_t->addLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(inv_l,inv) {
        Investigation *model_t = new Investigation();
        XInvestigation *xml_t = new XInvestigation(model_t,inv_l.link);
        xml_t->readData();
        model_t->addLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(dr_l,drug) {
        Drug *model_t = new Drug();
        XDrug *xml_t = new XDrug(model_t,dr_l.link);
        xml_t->readData();
        model_t->addLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(sur_l,sur) {
        Surgery *model_t = new Surgery();
        XSurgery *xml_t = new XSurgery(model_t,sur_l.link);
        xml_t->readData();
        model_t->addLink(old_item.getLocation());
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    //Save the model by overwriting the old file
    XAppointment *xml = new XAppointment(model,old_item.getLocation());
    xml->saveData();
    IndexItem item(date_e->date(),old_item.getLocation(),0,old_item.getDisease());
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
