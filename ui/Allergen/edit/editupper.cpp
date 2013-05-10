#include "editupper.h"

EditUpper::EditUpper(QString name_a, QWidget *parent) :
    QWidget(parent)
{
    l=new QLabel("Allergy name");
    line=new QLineEdit(name_a);
    h=new QHBoxLayout(this);
    h->addWidget(l);
    h->addWidget(line);
}

void EditUpper::resetAll()  {
    line->clear();
}

QString EditUpper::getName()    {
    return line->text();
}
