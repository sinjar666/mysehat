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

#ifndef ALLERGEN_H
#define ALLERGEN_H

#include <QObject>
#include <QDate>

#define ID_TYPE QString



class Allergen : public QObject
{
    Q_OBJECT
    QString *name,*drug_id;
    QDate *date; //When it was diagnosed

public:
    typedef enum    {
        drug_t,natural_t,synthetic_t,food_t
    } A_type;

    explicit Allergen(QObject *parent = 0);
    ~Allergen();

    void setName(QString arg);
    QString getName();

    void setType(A_type arg);
    A_type getType();

    void setDrug(QString arg);
    QString getDrug();

    void setDate(int day,int month,int year);
    void setDate(QDate arg);
    QDate getDate();

private:
     A_type type;

signals:

public slots:

};

#endif // ALLERGEN_H
