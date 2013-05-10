#include "idgen.h"

IdGen::IdGen(QString arg, QObject *parent) :
    QObject(parent)
{
    rootPath = arg;
    QDir temp(rootPath);
    temp.cdUp();
    configPath = temp.absolutePath();
    conf_engine = new Config(configPath+"/");
}
IdGen::~IdGen()
{
    conf_engine->deleteLater();
}

QString IdGen::generate(ItemType arg)   {
    quint16 t;
    switch(arg) {
    case APPOINTMENT_T:
        appointment=conf_engine->readData(QString("appointment"));
        t=appointment.toUInt();
        t++;
        appointment=QString::number(t);
        conf_engine->writeData(QString("appointment"),appointment);
        return (rootPath+"/app"+appointment+".xml");
        break;
    case SYMPTOM_T:
        symptom=conf_engine->readData(QString("symptom"));
        t=symptom.toUInt();
        t++;
        symptom=QString::number(t);
        conf_engine->writeData(QString("symptom"),symptom);
        return (rootPath+"/sym"+symptom+".xml");
        break;

    case ALLERGEN_T:
        allergen = conf_engine->readData(QString("allergen"));
        t=allergen.toUInt();
        t++;
        allergen=QString::number(t);
        conf_engine->writeData(QString("allergen"),allergen);
        return (rootPath+"/all"+allergen+".xml");
        break;
    case DRUG_T:
        drug = conf_engine->readData(QString("drug"));
        t=drug.toUInt();
        t++;
        drug=QString::number(t);
        conf_engine->writeData(QString("drug"),drug);
        return (rootPath+"/dru"+drug+".xml");
        break;
    case INVESTIGATION_T:
        investigation = conf_engine->readData(QString("investigation"));
        t=investigation.toUInt();
        t++;
        investigation=QString::number(t);
        conf_engine->writeData(QString("investigation"),investigation);
        return (rootPath+"/inv"+investigation+".xml");
        break;
    case SURGERY_T:
        surgery = conf_engine->readData(QString("surgery"));
        t=surgery.toUInt();
        t++;
        surgery=QString::number(t);
        conf_engine->writeData(QString("surgery"),surgery);
        return (rootPath+"/sur"+surgery+".xml");
        break;
    case FAMILYHIST_T:
        familyhist = conf_engine->readData(QString("familyhistory"));
        t=familyhist.toUInt();
        t++;
        familyhist=QString::number(t);
        conf_engine->writeData(QString("familyhistory"),familyhist);
        return (rootPath+"/fam"+familyhist+".xml");
        break;
    case VACCINE_T:
        vaccine = conf_engine->readData(QString("vaccine"));
        t=vaccine.toUInt();
        t++;
        vaccine=QString::number(t);
        conf_engine->writeData(QString("vaccine"),vaccine);
        return (rootPath+"/vac"+vaccine+".xml");
        break;
    }

}
