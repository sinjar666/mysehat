#include "itemwidget.h"

ItemWidget::ItemWidget(const QPixmap img, QString descr, QString type, QDate date,QString disease,QWidget *parent) :
    QWidget(parent)
{
    QPixmap scaledImg = img.scaled(100,100);
    icon = new QLabel();
    icon->setPixmap(scaledImg);
    w = new RWid(descr,type,date,disease);
    layout = new QHBoxLayout(this);
    layout->addWidget(icon);
    layout->addWidget(w);
    //setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}
QSize ItemWidget::sizeHint() const  {
    return(QSize(790,100));
}
