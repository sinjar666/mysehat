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

#include "familyhistory.h"

FamilyHistory::FamilyHistory(QObject *parent) :
    QObject(parent)
{
    id = new ID_TYPE();
    members=0;
    name = new QString();
}

FamilyHistory::~FamilyHistory() {
    delete(id);
    delete(name);
}

void FamilyHistory::setName(QString arg)    {
    *name=arg;
}
QString FamilyHistory::getName()    {
    return *name;
}

void FamilyHistory::addMember(Members arg)  {
    members |= arg;
}

bool FamilyHistory::isMother()  {
    return ((members & MOTHER_T) > 0 ? true : false);
}
bool FamilyHistory::isFather()  {
    return ((members & FATHER_T) > 0 ? true : false);
}
bool FamilyHistory::isBrother()  {
    return ((members & BROTHER_T) > 0 ? true : false);
}
bool FamilyHistory::isSister()  {
    return ((members & SISTER_T) > 0 ? true : false);
}
bool FamilyHistory::isGrandfather()  {
    return ((members & GRANDFATHER_T) > 0 ? true : false);
}
bool FamilyHistory::isGrandmother()  {
    return ((members & GRANDMOTHER_T) > 0 ? true : false);
}
quint8 FamilyHistory::getMembers()  {
    return members;
}
void FamilyHistory::setMembers(quint8 arg)  {
    members=arg;
}
