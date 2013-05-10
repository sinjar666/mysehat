#include "addappointmentwid.h"

AddAppointmentWid::AddAppointmentWid(QString rootdir,QWidget *parent) :
    QWidget(parent)
{
    path = rootdir;
    name_w = new AppointmentNameWid();
    dt = new AppointmentDateTimeWid();
    link_w = new AppointmentLinkWid();
    bottom = new AppointmentBottomBar();
    lay = new QVBoxLayout(this);
    lay->addWidget(name_w);
    lay->addWidget(dt);
    lay->addWidget(link_w);
    lay->addWidget(bottom);
    model = new Appointment();

    connect(bottom,SIGNAL(sendReset()),this,SLOT(performReset()));
    connect(bottom,SIGNAL(sendAdd()),this,SLOT(performSave()));
    connect(link_w,SIGNAL(addLinks(int)),this,SLOT(performAddLinks(int)));
}

void AddAppointmentWid::performAddLinks(int index)  {
    switch(index)   {
    case 0: {
        SearchDialog *sd = new SearchDialog(path+"/",Engine::SYMPTOM_F,model,this);
        sd->exec();
        break;
    }
    case 1:     {
        SearchDialog *sd = new SearchDialog(path+"/",Engine::DRUG_F,model,this);
        sd->exec();
        break;
    }
    case 2: {
        SearchDialog *sd = new SearchDialog(path+"/",Engine::SURGERY_F,model,this);
        sd->exec();
        break;
    }
    case 3: {
        SearchDialog *sd = new SearchDialog(path+"/",Engine::INVESTIGATION_F,model,this);
        sd->exec();
        break;
    }
    default:
        qDebug("Not possible.");
    }
}

void AddAppointmentWid::performReset()  {
    name_w->resetAll();
    dt->resetAll();
}

void AddAppointmentWid::performSave()    {
    if(name_w->getName().isEmpty()) {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the doctors name"));
    }
    else
    {
    IdGen *id_gen; //declare
    id_gen = new IdGen(path); //initialize
    QString id = id_gen->generate(IdGen::APPOINTMENT_T); //generate
    //Now we have the id in the variable "id"
    //Add the root path before the id so as to have a complete absolute path
    model->setName(name_w->getName());
    model->setDate(dt->getDate());
    model->setTime(dt->getTime());

    //Obtain list of new files from model
    syms = model->getSymptom();
    drug = model->getDrug();
    sur = model->getSurgery();
    inv = model->getInvestigation();
    symptomComplained sym_l;
    investigationAdvised inv_l;
    drugPrescribed dr_l;
    surgeryAdvised sur_l;
    //Add the back links in the new files
    foreach(sym_l,syms) {
        Symptom *model_t = new Symptom();
        XSymptom *xml_t = new XSymptom(model_t,sym_l.link);
        xml_t->readData();
        model_t->addLink(id);
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(inv_l,inv) {
        Investigation *model_t = new Investigation();
        XInvestigation *xml_t = new XInvestigation(model_t,inv_l.link);
        xml_t->readData();
        model_t->addLink(id);
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(dr_l,drug) {
        Drug *model_t = new Drug();
        XDrug *xml_t = new XDrug(model_t,dr_l.link);
        xml_t->readData();
        model_t->addLink(id);
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }
    foreach(sur_l,sur) {
        Surgery *model_t = new Surgery();
        XSurgery *xml_t = new XSurgery(model_t,sur_l.link);
        xml_t->readData();
        model_t->addLink(id);
        xml_t->saveData();
        xml_t->deleteLater();
        model_t->deleteLater();
    }


    XAppointment *xml = new XAppointment(model,id);
    xml->saveData();
    IndexItem index_item(dt->getDate(),id,0,QString());
    Engine *engine = new Engine(path+"/");
    engine->loadIndex();
    QStringList keys;
    KeyFinder *finder = new KeyFinder(name_w->getName());
    keys = finder->generate();
    QString key;
    foreach(key,keys)   {
        engine->addEntry(key,index_item);
    }
    engine->saveIndex();
    QFile fil(path+"/appoint_list");
    map_date.clear();
    if(fil.open(QIODevice::ReadOnly))
    {
        QDataStream in(&fil);
        in>>map_date;
    }
    fil.close();
    if(!fil.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug("file appoint_list cant be created");
    }
    else
    {
        //qDebug()<<dt->getDate().toString()+" "+path;
        map_date.insert(dt->getDate(),id);
        QDataStream out(&fil);
        out<<map_date;
    }
    fil.close();
    model->deleteLater();
    id_gen->deleteLater();
    xml->deleteLater();
    engine->deleteLater();
    finder->deleteLater();

    close();
    }
}
