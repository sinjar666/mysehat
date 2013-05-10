#include "editbottom.h"

EditBottom::EditBottom(QWidget *parent) :
    QWidget(parent)
{
    button1=new QPushButton("Save");
    button2=new QPushButton("Reset");
    h=new QHBoxLayout(this);
    h->addWidget(button1);
    h->addWidget(button2);
    connect(button1,SIGNAL(clicked()),this,SLOT(onSave()));
    connect(button2,SIGNAL(clicked()),this,SLOT(onReset()));
}

void EditBottom::onReset()   {
    emit resetPressed();
}

void EditBottom::onSave()    {
    emit savePressed();
}
