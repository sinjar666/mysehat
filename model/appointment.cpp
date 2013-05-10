#include "appointment.h"

Appointment::Appointment(QObject *parent) :
    QObject(parent)
{
    name = new QString();
    date = new QDate();
    time = new QTime();
    s_adv = new QList<surgeryAdvised>();
    i_adv = new QList<investigationAdvised>();
    d_pres = new QList<drugPrescribed>();
    s_cmp = new QList<symptomComplained>();
}

Appointment::~Appointment() {
    delete(name);
    delete(date);
    delete(time);
    delete(s_adv);
    delete(i_adv);
    delete(s_cmp);
    delete(d_pres);
}

void Appointment::setDate(int day, int month, int year) {
    date->setDate(year,month,day);
}

void Appointment::setDate(QDate arg)    {
    *date=arg;
}

QDate Appointment::getDate()    {
    return *date;
}

void Appointment::setName(QString arg)  {
    *name=arg;
}

QString Appointment::getName()  {
    return *name;
}

void Appointment::setTime(int hour, int min)  {
    time->setHMS(hour,min,0);
}

void Appointment::setTime(QTime arg)    {
    *time = arg;
}

QTime Appointment::getTime()    {
    return *time;
}

bool Appointment::addSurgery(surgeryAdvised arg)    {
    if(!s_adv->contains(arg))   {
        s_adv->append(arg);
        return true;
    }
    else return false;
}

bool Appointment::addDrug(drugPrescribed arg)   {
    if(!d_pres->contains(arg))  {
        d_pres->append(arg);
        return true;
    }
    else return false;
}

bool Appointment::addInvestigation(investigationAdvised arg)    {
    if(!i_adv->contains(arg))   {
        i_adv->append(arg);
        return true;
    }
    else return false;
}

bool Appointment::addSymptom(symptomComplained arg) {
    if(!s_cmp->contains(arg))   {
        s_cmp->append(arg);
        return true;
    }
    else return false;
}

QList<surgeryAdvised> Appointment::getSurgery()  {
    return *s_adv;
}

QList<investigationAdvised> Appointment::getInvestigation()  {
    return *i_adv;
}

QList<drugPrescribed> Appointment::getDrug()  {
    return *d_pres;
}

QList<symptomComplained> Appointment::getSymptom()  {
    return *s_cmp;
}

void Appointment::removeSymptom(symptomComplained arg)  {
    s_cmp->removeAt(s_cmp->indexOf(arg));
}

void Appointment::removeDrug(drugPrescribed arg)    {
    d_pres->removeAt(d_pres->indexOf(arg));
}

void Appointment::removeSurgery(surgeryAdvised arg) {
    s_adv->removeAt(s_adv->indexOf(arg));
}

void Appointment::removeInvestigation(investigationAdvised arg) {
    i_adv->removeAt(i_adv->indexOf(arg));
}

bool operator==(const symptomComplained &a,const symptomComplained &b)
{
    if(a.date==b.date && a.duration==b.duration && a.link==b.link)
        return true;
    else
        return false;
}
bool operator==(const drugPrescribed &a,const drugPrescribed &b)
{
    if(a.dosage==b.dosage && a.duration==b.duration && a.link==b.link)
        return true;
    else
        return false;
}
bool operator==(const investigationAdvised &a,const investigationAdvised &b)
{
    if(a.link==b.link)
        return true;
    else
        return false;
}
bool operator==(const surgeryAdvised &a,const surgeryAdvised &b)
{
    if(a.link==b.link)
        return true;
    else
        return false;
}
