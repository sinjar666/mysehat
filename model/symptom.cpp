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
