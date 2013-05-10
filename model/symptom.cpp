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

#include "symptom.h"

Symptom::Symptom(QObject *parent) :
    QObject(parent)
{
    description=new QString();
    characteristics = new QString();
    linkedTo = new QList<ID_TYPE>();
}

Symptom::~Symptom() {
    delete(description);
    delete(characteristics);
    delete(linkedTo);
}

QString Symptom::getDescription()   {
    return *description;
}

QString Symptom::getCharacteristics()   {
    return *characteristics;
}

void Symptom::setCharacteristics(QString arg)   {
    *characteristics=arg;
}

void Symptom::setDescription(QString arg)   {
    *description=arg;
}

QList<ID_TYPE> Symptom::getLinkedTo()   {
    return *linkedTo;
}

bool Symptom::addLink(ID_TYPE arg)  {
    if(!linkedTo->contains(arg))    {
        linkedTo->append(arg);
        return true;
    }
    else return false;
}

bool Symptom::removeLink(QString arg)   {
    return ((linkedTo->removeAll(arg))!=0)?true:false;

}
