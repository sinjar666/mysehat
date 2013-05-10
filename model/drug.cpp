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

#include "drug.h"

Drug::Drug(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    date = new QDate();
    name = new QString();
    linkedTo = new QList<ID_TYPE>();
}

Drug::~Drug()   {
    delete(id);
    delete(name);
    delete(date);
}

void Drug::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Drug::setDate(QDate arg)    {
    *date=arg;
}

QDate Drug::getDate()    {
    return *date;
}

void Drug::setName(QString arg) {
    *name=arg;
}

QString Drug::getName() {
    return *name;
}

void Drug::setDuration(quint16 arg) {
    duration=arg;
}
quint16 Drug::getDuration() {
    return duration;
}

QList<ID_TYPE> Drug::getLinkedTo()   {
    return *linkedTo;
}

bool Drug::addLink(ID_TYPE arg)  {
    if(!linkedTo->contains(arg))    {
        linkedTo->append(arg);
        return true;
    }
    else return false;
}

bool Drug::removeLink(QString arg)   {
    return ((linkedTo->removeAll(arg))!=0)?true:false;

}

