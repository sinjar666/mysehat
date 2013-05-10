#include "editinvestigationwid.h"

EditInvestigationWid::EditInvestigationWid(QString path_a,IndexItem olditem,QWidget *parent) :
    QWidget(parent)
{
    path=path_a;
    old_item=olditem;
    model=new Investigation();
    xml=new XInvestigation(model,old_item.getLocation());
    xml->readData();

    g_layout=new QGridLayout(this);
    //g_layout->setVerticalSpacing(10);

    date_l=new QLabel(tr("Date"));
    date_e=new QDateEdit(model->getDate());
    time_l=new QLabel(tr("Time"));
    time_e=new QTimeEdit(model->getTime());
    save_b=new QPushButton(tr("SAVE"));
    type_l=new QLabel(tr("Type"));
    type_c=new QComboBox();
    QStringList types;
    types << "Angiography" <<
             "Biopsy" << "Blood Test" <<
             "Colonoscopy" <<
             "CT" <<
             "ECG" <<
             "Echo Cardiography" <<
             "Electro Encephalography (EEG)" <<
             "Endoscopy" <<
             "FNAC" <<
             "Funduscopy" <<
             "Holter Test" <<
             "MRI" <<
             "Sputum Test" <<
             "Stool Test" <<
             "Throat Swab" <<
             "Treadmill" <<
             "Urine Test" <<
             "Ultrasonography (USG)" <<
             "X-Ray" <<
             "Other";

    type_c->addItems(types);
    type_c->setCurrentIndex((int)(model->getType()));
    detail_l=new QLabel(tr("Details"));
    detail_e=new QTextEdit(model->getDetails());
    report_l=new QLabel(tr("Report"));
    report_b=new QPushButton(tr("Capture Image"));
    browse_b = new QPushButton(tr("Browse"));
    reset_b = new QPushButton(tr("Reset"));
    g_layout->addWidget(date_l,0,0);
    g_layout->addWidget(date_e,0,1,1,2);
    g_layout->addWidget(time_l,1,0);
    g_layout->addWidget(time_e,1,1,1,2);
    g_layout->addWidget(type_l,2,0);
    g_layout->addWidget(type_c,2,1,1,2);
    g_layout->addWidget(detail_l,3,0);
    g_layout->addWidget(detail_e,3,1,1,2);
    g_layout->addWidget(report_l,4,0);
    g_layout->addWidget(report_b,4,1,1,1);
    g_layout->addWidget(browse_b,4,2,1,1);
    g_layout->addWidget(save_b,5,0);
    g_layout->addWidget(reset_b,5,1,1,2);
     //qDebug("idhar");
    connect(save_b,SIGNAL(clicked()),this,SLOT(perform_save()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(perform_reset()));
    connect(report_b,SIGNAL(clicked()),this,SLOT(perform_camera()));
    connect(browse_b,SIGNAL(clicked()),this,SLOT(perform_browse()));
    xml->deleteLater();
}

void EditInvestigationWid::perform_reset()
{
    date_e->setDate(QDate::currentDate());
    time_e->setTime(QTime::currentTime());
    type_c->setCurrentIndex(0);
    detail_e->clear();
}

void EditInvestigationWid::perform_browse()
{
    img_path = QFileDialog::getOpenFileName(this,"Choose image","/home/user/MyDocs",tr("Images (*.png *.xpm *.jpg)"));
}

void EditInvestigationWid::perform_camera()
{
    img_path=path+"/"+QString::number(QDateTime::currentMSecsSinceEpoch())+".jpg";
    camera_wid=new StillCam(img_path,this);
    camera_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
    camera_wid->setAttribute(Qt::WA_DeleteOnClose);
    camera_wid->setWindowFlags(camera_wid->windowFlags()|Qt::Window);
    connect(camera_wid,SIGNAL(done()),camera_wid,SLOT(close()));
    camera_wid->show();
}

void EditInvestigationWid::perform_save()
{
    if(detail_e->toPlainText().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the details"));
    }
    else
    {
    Engine *eng=new Engine(path);
    eng->loadIndex();
    QStringList keys;
    QString key;
    KeyFinder *keyfinder=new KeyFinder(model->getDetails());
    keys=keyfinder->generate();
    foreach(key,keys)   {
        eng->remove(key,old_item);
    }
    keyfinder->deleteLater();

    model->setDate(date_e->date());
    model->setTime(time_e->time());

    model->setDetails(detail_e->toPlainText());
    model->setType((Investigation::Type)(type_c->currentIndex()));

    xml=new XInvestigation(model,old_item.getLocation());
    xml->saveData();
    IndexItem item(date_e->date(),old_item.getLocation(),4,old_item.getDisease());
    keyfinder=new KeyFinder(model->getDetails());
    foreach(key,keys)   {
        eng->addEntry(key,item);
    }
    eng->saveIndex();
    eng->deleteLater();
    keyfinder->deleteLater();
    close();
    }
}
