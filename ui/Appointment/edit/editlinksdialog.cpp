#include "editlinksdialog.h"

EditLinksDialog::EditLinksDialog(QString path_a,Appointment *model_a, Engine::Filters type_a, QWidget *parent) :
    QDialog(parent)
{
    model=model_a;
    type=type_a;
    path_model=path_a;
    listModel.clear();
    switch(type)    {
    case Engine::SYMPTOM_F: {
        symptomComplained link;
        s_list = model->getSymptom();
        foreach(link,s_list) {
            Symptom *m = new Symptom();
            XSymptom *xml = new XSymptom(m,link.link);
            xml->readData();
            listModel << m->getDescription();
            xml->deleteLater();
            m->deleteLater();
        }
        break;
    }
    case Engine::DRUG_F:    {
        drugPrescribed link;
        d_list = model->getDrug();
        foreach(link,d_list) {
            Drug *m = new Drug();
            XDrug *xml = new XDrug(m,link.link);
            xml->readData();
            listModel << m->getName();
            xml->deleteLater();
            m->deleteLater();
        }
        break;
    }
    case Engine::SURGERY_F: {
        surgeryAdvised link;
        sur_list = model->getSurgery();
        foreach(link,sur_list) {
            Surgery *m = new Surgery();
            XSurgery *xml = new XSurgery(m,link.link);
            xml->readData();
            listModel << m->getDetails();
            xml->deleteLater();
            m->deleteLater();
        }
        break;
    }
    case Engine::INVESTIGATION_F:   {
        investigationAdvised link;
        i_list = model->getInvestigation();
        foreach(link,i_list) {
            Investigation *m = new Investigation();
            XInvestigation *xml = new XInvestigation(m,link.link);
            xml->readData();
            listModel << m->getDetails();
            xml->deleteLater();
            m->deleteLater();
        }
        break;
    }
    default:
        qDebug("Not possible");
    }
    list_widget = new QListWidget();
    list_widget->clear();
    list_widget->addItems(listModel);
    list_widget->setSelectionMode(QAbstractItemView::MultiSelection);
    del_b = new QPushButton(tr("Delete selected links"));
    all_b = new QPushButton(tr("Select all"));
    lay = new QGridLayout(this);
    lay->addWidget(list_widget,0,0,1,2);
    lay->addWidget(all_b,1,0);
    lay->addWidget(del_b,1,1);
    connect(all_b,SIGNAL(clicked()),this,SLOT(selectAll()));
    connect(del_b,SIGNAL(clicked()),this,SLOT(performDelete()));
}

void EditLinksDialog::selectAll()   {
    list_widget->selectAll();
}

void EditLinksDialog::performDelete()   {
    QList<QListWidgetItem *> items = list_widget->selectedItems();
    QListWidgetItem *item;
    switch(type)    {
    case Engine::SYMPTOM_F:
        foreach(item,items) {
            int i=list_widget->row(item);
            model->removeSymptom(s_list[i]);
            listModel.removeAt(i);
        }
        break;
    case Engine::DRUG_F:
        foreach(item,items) {
            int i=list_widget->row(item);
            model->removeDrug(d_list[i]);
            listModel.removeAt(i);
        }
        break;
    case Engine::SURGERY_F:
        foreach(item,items) {
            int i=list_widget->row(item);
            model->removeSurgery(sur_list[i]);
            listModel.removeAt(i);
        }
        break;
    case Engine::INVESTIGATION_F:
        foreach(item,items) {
            int i=list_widget->row(item);
            model->removeInvestigation(i_list[i]);
            listModel.removeAt(i);
        }
        break;
    default:
        qDebug("Not possible");
    }
    list_widget->clear();
    list_widget->addItems(listModel);
}

