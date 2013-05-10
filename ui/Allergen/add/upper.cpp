#include "upper.h"

upper::upper(QWidget *parent) :
    QWidget(parent)
{
    l=new QLabel("Allergy name");
    line=new QLineEdit();
    h=new QHBoxLayout(this);
    h->addWidget(l);
    h->addWidget(line);
}

void upper::resetAll()  {
    line->clear();
}

QString upper::getName()    {
    return line->text();
}
