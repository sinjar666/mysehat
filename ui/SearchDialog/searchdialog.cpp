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

#include "searchdialog.h"

SearchDialog::SearchDialog(QString path_a, Engine::Filters type_a, Appointment *res_m, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    setWindowTitle(tr("Search for an item and enter details (if applicable)"));
    res_model=res_m;
    results.clear();
    type=type_a;
    path=path_a;
    engine = new Engine(path);
    engine->loadIndex();
    engine->setFilter(type,true);
    searchbox = new QLineEdit();
    view_list = new QListWidget();
    search_b = new QPushButton(tr("Search"));
    //search_b->setFixedWidth(120);
    lay = new QGridLayout(this);
    lay->addWidget(searchbox,0,0,1,3);
    lay->addWidget(search_b,0,3,1,1);
    lay->addWidget(view_list,1,0,1,4);
    if(type==Engine::SYMPTOM_F) {
        date_e = new QDateEdit();
        duration_e = new QSpinBox();
        lay->addWidget(new QLabel(tr("Date")),2,0);
        lay->addWidget(date_e,2,1);
        lay->addWidget(new QLabel(tr("Duration (hrs)")),2,2);
        lay->addWidget(duration_e,2,3);
    }
    else if(type==Engine::DRUG_F)   {
        dosage_e = new QSpinBox();
        duration_e = new QSpinBox();
        lay->addWidget(new QLabel(tr("Dosage")),2,0);
        lay->addWidget(dosage_e,2,1);
        lay->addWidget(new QLabel(tr("Duration (days)")),2,2);
        lay->addWidget(duration_e,2,3);
    }
    add_b = new QPushButton(tr("Add Link to selected item"));
    lay->addWidget(add_b,4,0,1,4);
    lay->addWidget(new QLabel("   "),4,1);
    performSearch();
    //connect(searchbox,SIGNAL(textChanged(QString)),this,SLOT(performSearch(QString)));
    connect(searchbox,SIGNAL(returnPressed()),this,SLOT(performSearch()));
    connect(add_b,SIGNAL(clicked()),this,SLOT(onAddClicked()));
    connect(search_b,SIGNAL(clicked()),this,SLOT(performSearch()));

}

SearchDialog::~SearchDialog()   {
    engine->deleteLater();
}

void SearchDialog::performSearch()  {
    QString text=searchbox->text();
    //qDebug ()<< "searching:" << text;

        //qDebug("here");
        results.clear();
        view.clear();
        view_list->clear();
        results=engine->getSubstringMatch(text);
        //qDebug() << results.length();
        IndexItem item;
        switch(type)    {
        case Engine::SYMPTOM_F: {
            foreach(item,results)   {
                Symptom *model = new Symptom();
                XSymptom *xml = new XSymptom(model,item.getLocation());
                xml->readData();
                view << model->getDescription() + QString("(") + item.getDate().toString() +
                       QString(")");
                model->deleteLater();
                xml->deleteLater();
            }
            break;
         }

        case Engine::DRUG_F:    {
            foreach(item,results)   {
                Drug *model = new Drug();
                XDrug *xml = new XDrug(model,item.getLocation());
                xml->readData();
                view << model->getName() + QString("(") + model->getDate().toString() +
                        QString(")");
                model->deleteLater();
                xml->deleteLater();
            }
            break;
        }
        case Engine::SURGERY_F: {
            foreach(item,results)   {
                Surgery *model = new Surgery();
                XSurgery *xml = new XSurgery(model,item.getLocation());
                xml->readData();
                view << model->getDetails() + QString("(") + model->getDate().toString() +
                        QString(")");
                model->deleteLater();
                xml->deleteLater();
            }
            break;
        }
        case Engine::INVESTIGATION_F:   {
            foreach(item,results)   {
                Investigation *model = new Investigation();
                XInvestigation *xml = new XInvestigation(model,item.getLocation());
                xml->readData();
                view << model->getDetails() + QString("(") + model->getDate().toString() +
                        QString(")");
                model->deleteLater();
                xml->deleteLater();
            }
            break;
        }
        default:
            //Not possible
            break;
        }
        view_list->addItems(view);

}

void SearchDialog::onAddClicked()   {
    int index = view_list->currentRow();
    switch(type)    {
    case Engine::SYMPTOM_F: {
        symptomComplained obj;
        obj.date=date_e->date();
        obj.duration=duration_e->value();
        obj.link = results[index].getLocation();
        res_model->addSymptom(obj);
        break;
    }
    case Engine::DRUG_F:    {
        drugPrescribed obj;
        obj.dosage=dosage_e->value();
        obj.duration=duration_e->value();
        obj.link = results[index].getLocation();
        res_model->addDrug(obj);
        break;
    }
    case Engine::SURGERY_F: {
        surgeryAdvised obj;
        obj.link = results[index].getLocation();
        res_model->addSurgery(obj);
        break;
    }
    case Engine::INVESTIGATION_F:   {
        investigationAdvised obj;
        obj.link=results[index].getLocation();
        res_model->addInvestigation(obj);
        break;
    }
    default:
        //Not possible
        break;
    }
    accept();
}
