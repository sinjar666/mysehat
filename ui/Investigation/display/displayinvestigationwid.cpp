#include "displayinvestigationwid.h"

DisplayInvestigationwid::DisplayInvestigationwid(Investigation *arg,QWidget *parent) :
    QWidget(parent)
{
    model=arg;
    datetime = new QLabel(tr("Date/Time"));
    get_date = model->getDate().toString();
    get_time = model->getTime().toString();
    get_date.append(get_time);

    type = new QLabel(tr("Type"));
    detail_l=new QLabel(tr("Details"));
    report=new QLabel(tr("Report"));
    app_button=new QPushButton(tr("Appointments..."));
    get_report=model->getReport();
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
    get_type=types[model->getType()];
    get_detail=model->getDetails();
    datetimevalue = new QLabel(get_date);
    typevalue=new QLabel(get_type);
    detailvalue=new QLabel(get_detail);
    reportvalue=new QLabel(report);
    img_button = new QPushButton(tr("Show report.."));

    g_layout=new QGridLayout(this);
    g_layout->setVerticalSpacing(10);

    g_layout->addWidget(datetime,0,0);
    g_layout->addWidget(datetimevalue,0,1);
    g_layout->addWidget(type,1,0);
    g_layout->addWidget(typevalue,1,1);
    g_layout->addWidget(detail_l,2,0);
    g_layout->addWidget(detailvalue,2,1);
    g_layout->addWidget(report,3,0);
    g_layout->addWidget(reportvalue,3,1);
    g_layout->addWidget(app_button,4,0);
    g_layout->addWidget(img_button,4,1);

    connect(app_button,SIGNAL(clicked()),this,SLOT(displaylinks()));
    connect(img_button,SIGNAL(clicked()),this,SLOT(dipslayImage()));
}

void DisplayInvestigationwid::displaylinks()
{
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::APPOINTMENT_F,model->getLinkedTo(),&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayAppointment()));
    dialog->show();
}

void DisplayInvestigationwid::displayAppointment()
{
    DisplayAppointmentWid *widget;
    Appointment *model = new Appointment(this);
    XAppointment *xml = new XAppointment(model,to_open);
    xml->readData();
    xml->deleteLater();
    widget = new DisplayAppointmentWid(false,model,this);
    widget->setAttribute(Qt::WA_Maemo5StackedWindow);
    widget->setAttribute(Qt::WA_DeleteOnClose);
    widget->setWindowFlags(widget->windowFlags() | Qt::Window);
    widget->show();
}

void DisplayInvestigationwid::dipslayImage()    {
    DisplayReportsDialog *wid = new DisplayReportsDialog(model->getReport(),this);
    wid->setAttribute(Qt::WA_DeleteOnClose);
    wid->setAttribute(Qt::WA_Maemo5StackedWindow);
    wid->setWindowFlags(wid->windowFlags() | Qt::Window);
    wid->show();
}
