#include "displaysurgerywid.h"

DisplaySurgeryWid::DisplaySurgeryWid(Surgery *arg,QWidget *parent) :
    QWidget(parent)
{
    model=arg;
    g_layout=new QGridLayout(this);
    g_layout->setVerticalSpacing(10);

    date=new QLabel(tr("Date"));
    details=new QLabel(tr("Details"));

    datevalue=new QLabel(model->getDate().toString());
    detailsvalue=new QLabel(model->getDetails());

    app_button=new QPushButton(tr("Appointments..."));

    g_layout->addWidget(date,0,0);
    g_layout->addWidget(datevalue,0,1);
    g_layout->addWidget(details,1,0);
    g_layout->addWidget(detailsvalue,1,1);
    g_layout->addWidget(app_button,2,0);
    g_layout->addWidget(new QLabel(),2,1);

    connect(app_button,SIGNAL(clicked()),this,SLOT(displaylinks()));
}

void DisplaySurgeryWid::displaylinks()
{
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::APPOINTMENT_F,model->getLinkedTo(),&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayAppointment()));
    dialog->show();
}

void DisplaySurgeryWid::displayAppointment()
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
