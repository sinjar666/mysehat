#include "addfamilyhistorywid.h"

AddFamilyHistoryWid::AddFamilyHistoryWid(QString rootdir, QWidget *parent) :
    QWidget(parent)
{
    path=rootdir;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Disease name"));
    name_e = new QLineEdit();
    mother_e = new QCheckBox(tr("Mother"));
    father_e = new QCheckBox(tr("Father"));
    brother_e = new QCheckBox(tr("Brother"));
    sister_e = new QCheckBox(tr("Sister"));
    grandfather_e = new QCheckBox(tr("GrandFather"));
    grandmother_e = new QCheckBox(tr("GrandMother"));
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
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

void AddFamilyHistoryWid::performReset()    {
    mother_e->setChecked(false);
    father_e->setChecked(false);
    sister_e->setChecked(false);
    brother_e->setChecked(false);
    grandfather_e->setChecked(false);
    grandmother_e->setChecked(false);
    name_e->clear();
}

void AddFamilyHistoryWid::performSave()    {
    if(name_e->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the disease name"));
    }
    else
    {
    FamilyHistory *model = new FamilyHistory();
    IdGen *id_gen = new IdGen(path);
    QString id = id_gen->generate(IdGen::FAMILYHIST_T);
    model->setName(name_e->text());
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
    XFamilyHistory *xml= new XFamilyHistory(model,id);
    xml->saveData();
    IndexItem index_item(QDate::currentDate(),id,6,QString(""));
    Engine *engine = new Engine(path+"/");
    engine->loadIndex();
    QStringList keys;
    KeyFinder *finder = new KeyFinder(name_e->text());
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
