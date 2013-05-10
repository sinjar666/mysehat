#include "editsurgerywid.h"

EditSurgeryWid::EditSurgeryWid(QString path_a, IndexItem olditem, QWidget *parent):
    QWidget(parent)
{
    path=path_a;
    old_item=olditem;
    model=new Surgery();
    xml=new XSurgery(model,olditem.getLocation());
    xml->readData();

    g_layout=new QGridLayout(this);
    g_layout->setVerticalSpacing(10);

    date_l=new QLabel(tr("Date"));
    date_e=new QDateEdit(model->getDate());
    detail_l=new QLabel(tr("Detail"));
    detail_e=new QTextEdit(model->getDetails());

    save_b=new QPushButton(tr("SAVE"));
    reset_b=new QPushButton(tr("RESET"));

    g_layout->addWidget(date_l,0,0);
    g_layout->addWidget(date_e,0,1);
    g_layout->addWidget(detail_l,1,0);
    g_layout->addWidget(detail_e,1,1);
    g_layout->addWidget(save_b,2,0);
    g_layout->addWidget(reset_b,2,1);

    connect(save_b,SIGNAL(clicked()),this,SLOT(perform_save()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(perform_reset()));
    xml->deleteLater();
}

void EditSurgeryWid::perform_reset()
{
    date_e->setDate(QDate::currentDate());
    detail_e->clear();
}

void EditSurgeryWid::perform_save()
{
    if(detail_e->toPlainText().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the details"));
        //mesg->deleteLater();
    }
    else
    {
    Engine *engine = new Engine(path);
    engine->loadIndex();

    QStringList keys;
    QString key;
    KeyFinder *keyfinder = new KeyFinder(model->getDetails());
    keys = keyfinder->generate();
    foreach(key,keys)   {
        engine->remove(key,old_item);
    }
    keyfinder->deleteLater();

    model->setDate(date_e->date());

    model->setDetails(detail_e->toPlainText());

    xml=new XSurgery(model,old_item.getLocation());
    xml->saveData();
    IndexItem item(date_e->date(),old_item.getLocation(),5,old_item.getDisease());
    keyfinder = new KeyFinder(model->getDetails());
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
