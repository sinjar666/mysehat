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

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#define ID_TYPE QString
#include <QObject>
#include <QString>
#include <QDate>
#include <QTime>
#include <QMetaType>
#include <QList>

typedef struct     {

    ID_TYPE link;
    QDate date;
    int duration;
} symptomComplained;

Q_DECLARE_METATYPE(symptomComplained)
Q_DECLARE_METATYPE(QList<symptomComplained>)

typedef struct    {

    ID_TYPE link;
    int dosage;
    int duration; //in days
} drugPrescribed;

Q_DECLARE_METATYPE(drugPrescribed)
Q_DECLARE_METATYPE(QList<drugPrescribed>)

typedef struct    {

    ID_TYPE link;

} surgeryAdvised;

Q_DECLARE_METATYPE(surgeryAdvised)
Q_DECLARE_METATYPE(QList<surgeryAdvised>)

typedef struct  {

    ID_TYPE link;
} investigationAdvised;

Q_DECLARE_METATYPE(investigationAdvised)
Q_DECLARE_METATYPE(QList<investigationAdvised>)

class Appointment : public QObject
{
    Q_OBJECT
    ID_TYPE *id;
    QString *name; //Name of doctor
    QDate *date;
    QTime *time;
    QList<surgeryAdvised> *s_adv;
    QList<investigationAdvised> *i_adv;
    QList<drugPrescribed> *d_pres;
    QList<symptomComplained> *s_cmp;
public:

    explicit Appointment(QObject *parent = 0);
    ~Appointment();

    void setDate(QDate arg);
    void setDate(int day, int month, int year);
    QDate getDate();

    void setName(QString arg);
    QString getName();

    void setTime(QTime arg);
    void setTime(int hour,int min);
    QTime getTime();

    bool addSurgery(surgeryAdvised arg);
    bool addInvestigation(investigationAdvised arg);
    bool addDrug(drugPrescribed arg);
    bool addSymptom(symptomComplained arg);

    void removeSurgery(surgeryAdvised arg);
    void removeInvestigation(investigationAdvised arg);
    void removeDrug(drugPrescribed arg);
    void removeSymptom(symptomComplained arg);

    QList<surgeryAdvised> getSurgery();
    QList<investigationAdvised> getInvestigation();
    QList<drugPrescribed> getDrug();
    QList<symptomComplained> getSymptom();

signals:

public slots:

};
bool operator==(const symptomComplained &a,const symptomComplained &b);
bool operator==(const investigationAdvised &a,const investigationAdvised &b);
bool operator==(const drugPrescribed &a,const drugPrescribed &b);
bool operator==(const surgeryAdvised &a,const surgeryAdvised &b);



#endif // APPOINTMENT_H
