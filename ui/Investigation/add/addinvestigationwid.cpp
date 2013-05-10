#include "addinvestigationwid.h"

AddInvestigationWid::AddInvestigationWid(QString rootdir, QWidget *parent):
    QWidget(parent)
{
    path=rootdir;

    g_layout = new QGridLayout(this);
    g_layout->setVerticalSpacing(10);

    datetime = new QLabel(tr("Date/Time"));
    type = new QLabel(tr("Type"));
    date_t = new QDateTimeEdit();
    date_t->setDateTime(QDateTime::currentDateTime());
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
    dropdown = new QComboBox();
    dropdown->addItems(types);

    detail_l= new QLabel(tr("Details"));
    details = new QTextEdit();
    report = new QLabel(tr("Report"));
    imagepath = new QPushButton(tr("Capture image/video"));
    browse_b = new QPushButton(tr("Browse"));
    save = new QPushButton(tr("SAVE"));
    reset = new QPushButton(tr("RESET"));

    g_layout->addWidget(datetime,0,0);
    g_layout->addWidget(date_t,0,1,1,2);
    g_layout->addWidget(type,1,0);
    g_layout->addWidget(dropdown,1,1,1,2);
    g_layout->addWidget(detail_l,2,0);
    g_layout->addWidget(details,2,1,1,2);
    g_layout->addWidget(report,3,0);
    g_layout->addWidget(imagepath,3,1,1,1);
    g_layout->addWidget(browse_b,3,2,1,1);
    g_layout->addWidget(save,4,0);
    g_layout->addWidget(reset,4,1,1,2);

    connect(imagepath,SIGNAL(clicked()),this,SLOT(imagevideo()));
    connect(save,SIGNAL(clicked()),this,SLOT(perform_save()));
    connect(reset,SIGNAL(clicked()),this,SLOT(reset_function()));
    connect(browse_b,SIGNAL(clicked()),this,SLOT(browseClicked()));
}

void AddInvestigationWid::browseClicked()
{
    img_path = QFileDialog::getOpenFileName(this,"Choose image","/home/user/MyDocs",tr("Images (*.png *.xpm *.jpg)"));

}

void AddInvestigationWid::imagevideo()
{
    img_path=path+"/"+QString::number(QDateTime::currentMSecsSinceEpoch())+".jpg";
    camera_wid=new StillCam(img_path,this);
    camera_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
    camera_wid->setAttribute(Qt::WA_DeleteOnClose);
    camera_wid->setWindowFlags(camera_wid->windowFlags()|Qt::Window);
    connect(camera_wid,SIGNAL(done()),camera_wid,SLOT(close()));
    camera_wid->show();
}

void AddInvestigationWid::reset_function()
{
    date_t->setDateTime(QDateTime::currentDateTime());
    details->clear();
    dropdown->setCurrentIndex(0);
    img_path.clear();
}

void AddInvestigationWid::perform_save()
{
    if(details->toPlainText().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the details"));
    }
    else
    {
    model = new Investigation();
    IdGen *id_gen;
    id_gen = new IdGen(path);
    QString id=id_gen->generate(IdGen::INVESTIGATION_T);

    model->setDate(date_t->date());
    model->setTime(date_t->time());
    model->setDetails(details->toPlainText());
    model->setType((Investigation::Type)(dropdown->currentIndex()));
    model->setReport(img_path);

    XInvestigation *xml = new XInvestigation(model,id);
    xml->saveData();

    IndexItem *index_t=new IndexItem(date_t->date(),id,4,QString(""));

    Engine *eng=new Engine(path+"/");
    eng->loadIndex();

    QStringList keys;
    KeyFinder *keyfin=new KeyFinder(details->toPlainText());
    keys=keyfin->generate();

    QString key;
    foreach(key,keys)   {
        eng->addEntry(key,*index_t);
    }
    eng->saveIndex();
    model->deleteLater();
    xml->deleteLater();
    eng->deleteLater();
    keyfin->deleteLater();
    id_gen->deleteLater();
    delete(index_t);
    close();
    }
}
