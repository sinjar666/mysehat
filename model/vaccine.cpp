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

#include "vaccine.h"

Vaccine::Vaccine(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    name = new QString();
    date = new QDate();
}

Vaccine::~Vaccine() {
    delete(id);
    delete(name);
    delete(date);
}

void Vaccine::setName(QString arg)  {
    *name=arg;
}
QString Vaccine::getName()  {
    return *name;
}

void Vaccine::setValidity(quint16 arg)  {
    validity=arg;
}
quint16 Vaccine::getValidity()  {
    return validity;
}

void Vaccine::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Vaccine::setDate(QDate arg)    {
    *date=arg;
}

QDate Vaccine::getDate()    {
    return *date;
}
