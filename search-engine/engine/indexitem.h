/****************************************************************************************
 * Copyright (c) 2012 Srijan Mukherjee <srijanmukherjee06@yahoo.com>                    *
 * Copyright (c) 2012 Tumul Richesh <tumullko@gmail.com>                                *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 3 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

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
