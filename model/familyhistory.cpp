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
