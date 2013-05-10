#include "rwid.h"

RWid::RWid(QString descr,QString type,QDate date,QString disease,QWidget *parent) :
    QWidget(parent)
{
    QString str = descr.left(20);
    str = str + "...";
    descr_e = new QLabel(str);
    //descr_e->setReadOnly(true);
    w = new TypeDateWid(type,date,disease);
    layout = new QVBoxLayout(this);
    layout->addWidget(descr_e);
    layout->addWidget(w);
    //setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}

QSize RWid::sizeHint() const    {
    return(QSize(725,100));
}
