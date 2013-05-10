#include "displayappointmentwid.h"

DisplayAppointmentWid::DisplayAppointmentWid(bool links, Appointment *arg, QWidget *parent) :
    QWidget(parent)
{
    model=arg;
   // path=path_a;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLabel(model->getName());
    date_l = new QLabel(tr("Date"));
    date_e = new QLabel(model->getDate().toString());
    time_l = new QLabel(tr("Time"));
    time_e = new QLabel(model->getTime().toString());
    if(links)   {
        sym_b = new QPushButton(tr("Symptoms.."));
        drug_b = new QPushButton(tr("Drug.."));
        sur_b = new QPushButton(tr("Surgery"));
        inv_b = new QPushButton(tr("Investigations"));
    }
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(time_l,2,0);
    lay->addWidget(time_e,2,1);
    if(links)   {
        lay->addWidget(sym_b,3,0);
        lay->addWidget(drug_b,3,1);
        lay->addWidget(sur_b,4,0);
        lay->addWidget(inv_b,4,1);
        connect(sym_b,SIGNAL(clicked()),this,SLOT(showSymptoms()));
        connect(drug_b,SIGNAL(clicked()),this,SLOT(showDrugs()));
        connect(sur_b,SIGNAL(clicked()),this,SLOT(showSurgery()));
        connect(inv_b,SIGNAL(clicked()),this,SLOT(showInvestigations()));
    }
}

void DisplayAppointmentWid::showSymptoms()  {
    disp_wid_type=0;
    QList<QString> tmp;
    symptomComplained item;
    QList<symptomComplained> items = model->getSymptom();

    foreach(item,items)   {
        tmp.append(item.link);
    }
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::SYMPTOM_F,tmp,&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayWidget()));
    dialog->exec();
}

void DisplayAppointmentWid::showDrugs()  {
    disp_wid_type=1;
    QList<QString> tmp;
    drugPrescribed item;
    foreach(item,model->getDrug())   {
        tmp.append(item.link);
    }
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::DRUG_F,tmp,&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayWidget()));
    dialog->exec();
}

void DisplayAppointmentWid::showSurgery()  {
    disp_wid_type=2;
    QList<QString> tmp;
    surgeryAdvised item;
    foreach(item,model->getSurgery())   {
        tmp.append(item.link);
    }
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::SURGERY_F,tmp,&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayWidget()));
    dialog->exec();
}

void DisplayAppointmentWid::showInvestigations()  {
    disp_wid_type=3;
    QList<QString> tmp;
    investigationAdvised item;
    foreach(item,model->getInvestigation())   {
        tmp.append(item.link);
    }
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::INVESTIGATION_F,tmp,&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayWidget()));
    dialog->exec();
}

void DisplayAppointmentWid::displayWidget() {
    switch(disp_wid_type)   {
    case 0: {
        DisplaySymptomWid *widget;
        Symptom *model = new Symptom(this);
        XSymptom *xml = new XSymptom(model,to_open);
        xml->readData();
        xml->deleteLater();
        widget = new DisplaySymptomWid(model,this);
        widget->setAttribute(Qt::WA_Maemo5StackedWindow);
        widget->setAttribute(Qt::WA_DeleteOnClose);
        widget->setWindowFlags(widget->windowFlags() | Qt::Window);
        widget->show();
        break;
    }
    case 1: {
        DisplayDrugWid *widget;
        Drug *model = new Drug(this);
        XDrug *xml = new XDrug(model,to_open);
        xml->readData();
        xml->deleteLater();
        widget = new DisplayDrugWid(model,this);
        widget->setAttribute(Qt::WA_Maemo5StackedWindow);
        widget->setAttribute(Qt::WA_DeleteOnClose);
        widget->setWindowFlags(widget->windowFlags() | Qt::Window);
        widget->show();
        break;
    }
    case 2: {
        DisplaySurgeryWid *widget;
        Surgery *model = new Surgery(this);
        XSurgery *xml = new XSurgery(model,to_open);
        xml->readData();
        xml->deleteLater();
        widget = new DisplaySurgeryWid(model,this);
        widget->setAttribute(Qt::WA_Maemo5StackedWindow);
        widget->setAttribute(Qt::WA_DeleteOnClose);
        widget->setWindowFlags(widget->windowFlags() | Qt::Window);
        widget->show();
        break;
    }
    case 3: {
        DisplayInvestigationwid *widget;
        Investigation *model = new Investigation(this);
        XInvestigation *xml = new XInvestigation(model,to_open);
        xml->readData();
        xml->deleteLater();
        widget = new DisplayInvestigationwid(model,this);
        widget->setAttribute(Qt::WA_Maemo5StackedWindow);
        widget->setAttribute(Qt::WA_DeleteOnClose);
        widget->setWindowFlags(widget->windowFlags() | Qt::Window);
        widget->show();
        break;

    }
    default:
        qDebug("Do Nothing.");
    }
}
