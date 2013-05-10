#ifndef INDEXITEM_H
#define INDEXITEM_H

#include <QString>
#include <QDebug>
#include <QDate>
#include <QDataStream>

class IndexItem
{
    QDate date;
    QString location,disease;
    quint8 type;
    /*-----type spec-----------------
            ---0x00 = appointment
            ---0x01 = symptom
            ---0x02 = allergen
            ---0x03 = drug
            ---0x04 = investigation
            ---0x05 = surgery
            ---0x06 = family history
            ---0x07 = vaccine------------------*/

public:
    IndexItem()    {}
    IndexItem(const IndexItem &other);
    IndexItem(QDate date_arg,QString loc_arg,quint8 type_arg,QString disease_arg);

    IndexItem &operator=(const IndexItem &o);


    QDate getDate() const;
    QString getLocation() const;
    quint8 getType() const;
    QString getDisease() const;


};
QDataStream & operator<<(QDataStream & stream,const IndexItem & item);
QDataStream & operator>>(QDataStream & in,IndexItem & item);
bool operator==(const IndexItem & a,const IndexItem & b);
#endif // INDEXITEM_H
