#include "editsymptomwid.h"

EditSymptomWid::EditSymptomWid(QString path_a,IndexItem olditem,QWidget *parent) :
    QWidget(parent)
{
    path=path_a;
    old_item=olditem;
    model=new Symptom();
    xml=new XSymptom(model,old_item.getLocation());
    xml->readData();

    g_layout=new QGridLayout(this);
    g_layout->setVerticalSpacing(10);

    details_l=new QLabel(tr("Details"));
    desc=new QTextEdit(model->getDescription());
    charac_l=new QLabel(tr("Characteristics"));
    charac=new QLineEdit(model->getCharacteristics());

    save_b=new QPushButton(tr("SAVE"));
    reset_b=new QPushButton(tr("RESET"));

    g_layout->addWidget(details_l,0,0);
    g_layout->addWidget(desc,0,1);
    g_layout->addWidget(charac_l,1,0);
    g_layout->addWidget(charac,1,1);
    g_layout->addWidget(save_b,2,0);
    g_layout->addWidget(reset_b,2,1);

    connect(save_b,SIGNAL(clicked()),this,SLOT(perform_save()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(perform_reset()));

    xml->deleteLater();
}

void EditSymptomWid::perform_reset()
{
    desc->clear();
    charac->clear();
}

void EditSymptomWid::perform_save()
{
    if(charac->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the characteristics"));

    }
    else
    {
    Engine *engine = new Engine(path);
    engine->loadIndex();

    QStringList keys;
    QString key;
    KeyFinder *keyfinder = new KeyFinder(model->getCharacteristics());
    keys = keyfinder->generate();
    foreach(key,keys)   {
        engine->remove(key,old_item);
    }
    keyfinder->deleteLater();


    model->setCharacteristics(charac->text());
    model->setDescription(desc->toPlainText());

    xml = new XSymptom(model,old_item.getLocation());
    xml->saveData();

    //no date variable in Symptom Widget
    IndexItem item(old_item.getDate(),old_item.getLocation(),1,old_item.getDisease());
    keyfinder = new KeyFinder(model->getCharacteristics());
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
