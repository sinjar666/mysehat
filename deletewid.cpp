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

#include "deletewid.h"

DeleteWid::DeleteWid(QString path_a,IndexItem old_item,QObject *parent) :
    QObject(parent)
{
    path=path_a;

    //Removing backlinks from a file
    symptomComplained sym_l;
    drugPrescribed dr_l;
    surgeryAdvised sur_l;
    investigationAdvised inv_l;

    switch(old_item.getType())
    {
    case 0:
    {
        model_app= new Appointment();
        XAppointment *xml = new XAppointment(model_app,old_item.getLocation());
        xml->readData();
        syms = model_app->getSymptom();
        drug = model_app->getDrug();
        sur = model_app->getSurgery();
        inv = model_app->getInvestigation();

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
        model_app->deleteLater();
        xml->deleteLater();
        break;
    }
     case 1:
    {
        QList<QString> app_list;
        QString app;
        model_sym=new Symptom();
        XSymptom *xml=new XSymptom(model_sym,old_item.getLocation());
        xml->readData();
        app_list=model_sym->getLinkedTo();

        foreach(app,app_list)
        {
            Appointment *model_t=new Appointment();
            XAppointment *xml_t=new XAppointment(model_t,app);
            xml_t->readData();
            syms=model_t->getSymptom();

            foreach(sym_l,syms)
            {
                if(sym_l.link==old_item.getLocation())
                {
                    qDebug("matched.");
                    model_t->removeSymptom(sym_l);
                    break;
                }
            }
            xml_t->saveData();
            xml_t->deleteLater();
        }
        xml->deleteLater();
        model_sym->deleteLater();
        break;
    }
    case 2:
         break;
    case 3:
    {
        QList<QString> app_list;
        QString app;
        model_drug=new Drug();
        XDrug *xml=new XDrug(model_drug,old_item.getLocation());
        xml->readData();
        app_list.clear();
        app_list=model_drug->getLinkedTo();
        //qDebug("up to before foreach");
        foreach(app,app_list)
        {
            Appointment *model_t=new Appointment();
            XAppointment *xml_t=new XAppointment(model_t,app);
            xml_t->readData();
            drug=model_t->getDrug();

            foreach(dr_l,drug)
            {
                if(dr_l.link==old_item.getLocation())
                {    model_t->removeDrug(dr_l);
                     break;
                }
            }
            xml_t->saveData();
            xml_t->deleteLater();
        }
        //qDebug("after foreach");
        xml->deleteLater();
        model_drug->deleteLater();
        break;
    }
    case 4:
    {
        QList<QString> app_list;
        QString app;
        model_inv=new Investigation();
        XInvestigation *xml=new XInvestigation(model_inv,old_item.getLocation());
        xml->readData();
        app_list=model_inv->getLinkedTo();

        foreach(app,app_list)
        {
            Appointment *model_t=new Appointment();
            XAppointment *xml_t=new XAppointment(model_t,app);
            xml_t->readData();
            inv=model_t->getInvestigation();

            foreach(inv_l,inv)
            {
                if(inv_l.link==old_item.getLocation())
                {   model_t->removeInvestigation(inv_l);
                    break;
                }
            }
            xml_t->saveData();
            xml_t->deleteLater();
        }
        xml->deleteLater();
        model_inv->deleteLater();
        break;
    }
    case 5:
    {
        QList<QString> app_list;
        QString app;
        model_sur=new Surgery();
        XSurgery *xml=new XSurgery(model_sur,old_item.getLocation());
        xml->readData();
        app_list=model_sur->getLinkedTo();

        foreach(app,app_list)
        {
            Appointment *model_t=new Appointment();
            XAppointment *xml_t=new XAppointment(model_t,app);
            xml_t->readData();
            sur=model_t->getSurgery();

            foreach(sur_l,sur)
            {
                if(sur_l.link==old_item.getLocation())
                {    model_t->removeSurgery(sur_l);
                    break;
                }
            }
            xml_t->saveData();
            xml_t->deleteLater();
        }
        xml->deleteLater();
        model_sur->deleteLater();
        break;
    }
    case 6:
        break;
    case 7:
        break;
    }

    Engine *engine = new Engine(path+"/");
    engine->loadIndex();
    QList<QString> keys;
    QString key;

    keys = engine->getKeys(old_item);
    foreach(key,keys)
    {
        engine->remove(key,old_item);
    }
    engine->saveIndex();

    //Removing the file
    QFile fil(old_item.getLocation());
    if(fil.remove())
        qDebug("File removed");
    else
        qDebug("File not removed");

    engine->deleteLater();
}
