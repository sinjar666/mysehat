#include "appointmentbutton.h"

AppointmentButton::AppointmentButton(QString path_a,QWidget *parent) :
    QPushButton(parent)
{
    path=path_a;
    h_layout=new QHBoxLayout(this);
    model=new Appointment();
    xappoint=new XAppointment(model,path);
    xappoint->readData();

    date_value=model->getDate();
    doc_name=model->getName();
    if(doc_name.length() >20)  {
        doc_name.truncate(20);
        doc_name.append(tr("..."));
    }
    //date_l = new QLabel("<font size=\"5\">"+date_value.toString()+"</font>");
    date_l = new QLabel(date_value.toString());
    date_l->setAlignment(Qt::AlignRight);
    //docname_l=new QLabel("<font size=\"5\">"+doc_name+"</font>");
    docname_l = new QLabel(doc_name);
    docname_l->setAlignment(Qt::AlignLeft);
    docname_l->setFont(QFont(tr("Nokia"),28));
    date_l->setFont(QFont(tr("Nokia"),28));
    //h_layout->setMargin(0);

    h_layout->addWidget(docname_l);
    h_layout->addWidget(date_l);

    connect(this,SIGNAL(clicked()),this,SLOT(appointClicked()));
}

QSize AppointmentButton::sizeHint() const
{
    return(QSize(740,70));
}

void AppointmentButton::appointClicked()
{
    emit AppointItemClicked(path);
}
