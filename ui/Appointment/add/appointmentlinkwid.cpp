#include "appointmentlinkwid.h"

AppointmentLinkWid::AppointmentLinkWid(QWidget *parent) :
    QWidget(parent)
{
    chooser = new QComboBox();
    QStringList items;
    items << "Symptom" << "Drug" << "Surgery" << "Investigation";
    chooser->addItems(items);
    link_b = new QPushButton(tr("Add Link"));
    lay = new QHBoxLayout(this);
    lay->addWidget(chooser);
    lay->addWidget(link_b);
    connect(link_b,SIGNAL(clicked()),this,SLOT(onButtonClicked()));
}


void AppointmentLinkWid::onButtonClicked()  {
    emit addLinks(chooser->currentIndex());
}
