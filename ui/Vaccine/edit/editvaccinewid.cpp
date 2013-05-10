#include "editvaccinewid.h"

EditVaccineWid::EditVaccineWid(QString path_a, IndexItem olditem, QWidget *parent) :
    QWidget(parent)
{
    path=path_a;
    old_item = olditem;
    model = new Vaccine();
    xml = new XVaccine(model,olditem.getLocation());
    xml->readData();
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit(model->getName());
    date_l = new QLabel(tr("Date"));
    date_e = new QDateEdit(model->getDate());
    validity_l = new QLabel(tr("Validity"));
    validity_e = new QSpinBox();
    validity_e->setValue(model->getValidity());
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QGridLayout(this);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(validity_l,2,0);
    lay->addWidget(validity_e,2,1);
    lay->addWidget(save_b,3,0);
    lay->addWidget(reset_b,3,1);
    connect(save_b,SIGNAL(clicked()),this,SLOT(performSave()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(performReset()));
}

void EditVaccineWid::performReset() {
    name_e->clear();
    date_e->setDate(QDate::currentDate());
    validity_e->setValue(0);
}

void EditVaccineWid::performSave()  {
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
    model->setDate(date_e->date());
    model->setValidity(validity_e->value());
    xml->saveData();
    IndexItem item(date_e->date(),old_item.getLocation(),7,old_item.getDisease());
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
