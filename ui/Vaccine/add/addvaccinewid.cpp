#include "addvaccinewid.h"

AddVaccineWid::AddVaccineWid(QString rootdir,QWidget *parent) :
    QWidget(parent)
{
    path = rootdir;
    lay = new QVBoxLayout(this);
    det_w = new VaccineDetailsWid();
    bottom = new VaccineBottomWid();
    lay->addWidget(det_w);
    lay->addWidget(bottom);
    connect(bottom,SIGNAL(sendSave()),this,SLOT(performSave()));
    connect(bottom,SIGNAL(sendReset()),this,SLOT(performReset()));
}

void AddVaccineWid::performReset()  {
    det_w->resetAll();
}

void AddVaccineWid::performSave()   {
    if(det_w->getName().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the vaccine"));
    }
    else
    {
    Vaccine *model = new Vaccine();
    //qDebug()<<"This is the path "+path;
    IdGen *id_gen = new IdGen(path);
    QString id = id_gen->generate(IdGen::VACCINE_T);
    model->setName(det_w->getName());
    model->setDate(det_w->getDate());
    model->setValidity(det_w->getValidity());
    XVaccine *xml = new XVaccine(model,id);
    xml->saveData();
    IndexItem index_item(det_w->getDate(),id,7,QString(""));
    Engine *engine = new Engine(path + "/");
    engine->loadIndex();
    QStringList keys;
    KeyFinder *finder = new KeyFinder(det_w->getName());
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
