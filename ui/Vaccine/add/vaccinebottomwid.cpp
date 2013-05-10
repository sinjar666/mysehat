#include "vaccinebottomwid.h"

VaccineBottomWid::VaccineBottomWid(QWidget *parent) :
    QWidget(parent)
{
    save_b = new QPushButton(tr("Save"));
    reset_b = new QPushButton(tr("Reset"));
    lay = new QHBoxLayout(this);
    lay->addWidget(save_b);
    lay->addWidget(reset_b);
    connect(save_b,SIGNAL(clicked()),this,SLOT(onSavePressed()));
    connect(reset_b,SIGNAL(clicked()),this,SLOT(onResetPressed()));
}

void VaccineBottomWid::onResetPressed() {
    emit sendReset();
}

void VaccineBottomWid::onSavePressed()  {
    emit sendSave();
}
