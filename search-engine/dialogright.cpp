#include "dialogright.h"

DialogRight::DialogRight(QWidget *parent) :
    QWidget(parent)
{
    //uroot=uroot_a;
    lay = new QVBoxLayout(this);
    new_b = new QPushButton(tr("New..."));
    choose_b = new QPushButton(tr("Choose"));
    lay->addWidget(new_b);
    lay->addWidget(choose_b);
    connect(new_b,SIGNAL(clicked()),this,SLOT(onNew()));
    connect(choose_b,SIGNAL(clicked()),this,SLOT(onChoose()));
}

void DialogRight::onChoose()    {
    emit choosePressed();
}

void DialogRight::onNew()   {
   emit newPressed();
}
