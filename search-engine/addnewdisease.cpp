#include "addnewdisease.h"

AddNewDisease::AddNewDisease(QString *name_a,QWidget *parent) :
    QDialog(parent)
{
    name = name_a;
    setModal(true);
    lay = new QHBoxLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLineEdit();
    add_b = new QPushButton(tr("Add"));
    lay->addWidget(name_l);
    lay->addWidget(name_e);
    lay->addWidget(add_b);
    connect(add_b,SIGNAL(clicked()),this,SLOT(performAdd()));
}

void AddNewDisease::performAdd()    {
    *name = name_e->text();
    accept();
}
