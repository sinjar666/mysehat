#include "appointmentlist.h"

AppointmentList::AppointmentList(
    QList<AppointmentButton *> list_a,QWidget *parent) :
    QWidget(parent)
{
    v_layout = new QVBoxLayout(this);
    addButtons(list_a);
}

void AppointmentList::addButtons(QList<AppointmentButton *> list)
{
    AppointmentButton *i;
    if(list.length()==0)
    {
        QLabel *app_label=new QLabel("<font size=\"7\">No appointments found</font>");
        v_layout->addWidget(app_label);
    }
    else
    {
        QLabel *app_label=new QLabel("<font size=\"5\">List of Appointments<font>");
        v_layout->addWidget(app_label);
        foreach(i,list)
        {
            v_layout->addWidget(i);
        }
    }
}
