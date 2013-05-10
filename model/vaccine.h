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

#ifndef VACCINE_H
#define VACCINE_H

#include <QObject>
#include <QString>
#include <QDate>

#define ID_TYPE QString

class Vaccine : public QObject
{
    Q_OBJECT
    ID_TYPE *id;
    QString *name;
    quint16 validity; //in months, 0 indicates lifelong
    QDate *date;

public:
    explicit Vaccine(QObject *parent = 0);
    ~Vaccine();
    void setName(QString arg);
    QString getName();
    void setValidity(quint16 arg);
    quint16 getValidity();
    void setDate(QDate arg);
    void setDate(int day, int month, int year);
    QDate getDate();

signals:

public slots:

};

#endif // VACCINE_H
