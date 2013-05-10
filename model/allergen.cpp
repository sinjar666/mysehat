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

#include "allergen.h"

Allergen::Allergen(QObject *parent) :
    QObject(parent)
{
    name=new QString();
    date=new QDate();
    drug_id = new QString();
}

Allergen::~Allergen()   {
    delete(name);
    delete(date);
    delete(drug_id);
}

void Allergen::setName(QString arg) {
    *name=arg;
}
QString Allergen::getName()   {
    return *name;
}

void Allergen::setDate(int day, int month, int year)    {
    date->setDate(year,month,day);
}
void Allergen::setDate(QDate arg)   {
    *date=arg;
}
QDate Allergen::getDate()   {
    return *date;
}

void Allergen::setType(A_type arg)  {
    type=arg;
}

Allergen::A_type Allergen::getType()  {
    return type;
}

QString Allergen::getDrug() {
    return *drug_id;
}

void Allergen::setDrug(QString arg) {
    *drug_id=arg;
}
