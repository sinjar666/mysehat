#include "indexitem.h"

IndexItem::IndexItem(const IndexItem &other)    {
    *this=other;
}

IndexItem::IndexItem(QDate date_arg, QString loc_arg, quint8 type_arg,QString disease_arg)  {
    date=date_arg;
    location=loc_arg;
    type=type_arg;
    disease=disease_arg;
}

IndexItem & IndexItem::operator=(const IndexItem &o)   {
    date=o.getDate();
    location=o.getLocation();
    type=o.getType();
    disease=o.getDisease();
    return *this;
}

QDate IndexItem::getDate() const  {
    return date;
}
QString IndexItem::getLocation() const    {
    return location;
}
quint8 IndexItem::getType() const {
    return type;
}
QString IndexItem::getDisease() const   {
    return disease;
}

QDataStream & operator<<(QDataStream & stream,const IndexItem & item)    {
    stream << item.getDate().toJulianDay() << item.getLocation() << item.getType() << item.getDisease();
    return stream;
}

QDataStream & operator>>(QDataStream & in,IndexItem & item) {
    int jdate;
    QString loc_a,disease_a;
    quint8 type_a;
    in >> jdate >> loc_a >> type_a >> disease_a;
    //qDebug()<<sdate;
    item = IndexItem(QDate::fromJulianDay(jdate),loc_a,type_a,disease_a);
    return in;
}

bool operator ==(const IndexItem & a, const IndexItem & b)  {
    if(a.getDate() == b.getDate() && a.getLocation() == b.getLocation() && a.getType() == b.getType() && a.getDisease()==b.getDisease())
        return true;
    else return false;
}
