#ifndef IDGEN_H
#define IDGEN_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QDir>
#include "config/config.h"

class IdGen : public QObject
{
    Q_OBJECT
    QString appointment,symptom,allergen,drug,
            investigation,surgery,vaccine,familyhist,rootPath;
    QString configPath;

    Config *conf_engine;

public:
    typedef enum    {
        APPOINTMENT_T = 0,
        SYMPTOM_T = 1,
        ALLERGEN_T = 2,
        DRUG_T = 3,
        INVESTIGATION_T = 4,
        SURGERY_T = 5,
        VACCINE_T = 6,
        FAMILYHIST_T = 7
    } ItemType;

    explicit IdGen(QString arg,QObject *parent = 0);
    ~IdGen();
    QString generate(ItemType arg);

signals:

public slots:

};

#endif // IDGEN_H
