#include "addsymptomwid.h"

AddSymptomWid::AddSymptomWid(QString rootdir,QWidget *parent) :
    QWidget(parent)
{
    path=rootdir;
    g_layout= new QGridLayout(this);
    g_layout->setVerticalSpacing(20);

    char_l= new QLabel(tr("Characteristics"));
    desc= new QLabel(tr("Description"));
    details = new QTextEdit();
    charac = new QLineEdit();
    save = new QPushButton(tr("SAVE"));
    reset = new QPushButton(tr("RESET"));

    g_layout->addWidget(char_l,0,0);
    g_layout->addWidget(charac,0,1);
    g_layout->addWidget(desc,1,0);
    g_layout->addWidget(details,1,1);
    g_layout->addWidget(save,2,0);
    g_layout->addWidget(reset,2,1);

    connect(save,SIGNAL(clicked()),this,SLOT(perform_save()));
    connect(reset,SIGNAL(clicked()),this,SLOT(reset_function()));
}

void AddSymptomWid::reset_function()
{
    details->clear();
    charac->clear();
}

void AddSymptomWid::perform_save()
{
    if(charac->text().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the characteristics"));
    }
    else
    {
    model = new Symptom();
    IdGen *id_gen;
    id_gen = new IdGen(path);
    QString id = id_gen->generate(IdGen::SYMPTOM_T);

    model->setCharacteristics(charac->text());
    model->setDescription(details->toPlainText());

    XSymptom *xml = new XSymptom(model,id);
    xml->saveData();

    IndexItem *index_t=new IndexItem(QDate::currentDate(),id,1,QString(""));

    Engine *eng=new Engine(path+"/");
    eng->loadIndex();

    QStringList keys;
    KeyFinder *keyfin=new KeyFinder(charac->text());
    keys=keyfin->generate();

    QString key;
    foreach(key,keys)   {
        eng->addEntry(key,*index_t);
    }
    eng->saveIndex();
    model->deleteLater();
    id_gen->deleteLater();
    eng->deleteLater();
    keyfin->deleteLater();
    xml->deleteLater();
    delete(index_t);
    close();
    }
}
