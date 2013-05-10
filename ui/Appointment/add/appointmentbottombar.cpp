#include "appointmentbottombar.h"

AppointmentBottomBar::AppointmentBottomBar(QWidget *parent) :
    QWidget(parent)
{
    add_b = new QPushButton(tr("Add"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QHBoxLayout(this);
    lay->addWidget(add_b);
    lay->addWidget(reset_b);
    connect(reset_b,SIGNAL(clicked()),this,SLOT(onResetPressed()));
    connect(add_b,SIGNAL(clicked()),this,SLOT(onAddPressed()));
}

void AppointmentBottomBar::onResetPressed() {
    emit sendReset();
}

void AppointmentBottomBar::onAddPressed()   {
    emit sendAdd();
}
