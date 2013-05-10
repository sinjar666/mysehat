#include "typedatewid.h"

TypeDateWid::TypeDateWid(QString type, QDate date,QString disease,QWidget *parent) :
    QWidget(parent)
{
    QString str;
    str="<font color='red'>"+disease+"</font>"+"     "+"<font color='yellow'>"+type+"</font>";
    type_l = new QLabel(str);
    type_l->setTextFormat(Qt::RichText);
    date_l = new QLabel(date.toString());
    date_l->setAlignment(Qt::AlignRight);
    layout = new QHBoxLayout(this);
    layout->addWidget(type_l);
    layout->addWidget(date_l);
    //setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}
