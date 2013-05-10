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

#ifndef INVESTIGATION_H
#define INVESTIGATION_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QTime>

#define ID_TYPE QString
class Investigation : public QObject
{
    Q_OBJECT
    ID_TYPE *id;
    QDate *date;
    QTime *time;

    QString *details;
    QList<ID_TYPE> *linkedTo;
    QString *report;
public:
    typedef enum    {
        BLOODTEST_T=2,URINETEST_T=17,MRI_T=12,CT_T=4,XRAY_T=19,USG_T=18,THROATSWAB_T=15,
        ECG_T=5,ECHO_T=6,ANGIOGRAPHY_T=0,TREADMILL_T=16,EEG_T=7,FUNDUSCOPY_T=10,
        ENDOSCOPY_T=8,COLONOSCOPY_T=3,STOOLTEST_T=14,SPUTUM_T=13,FNAC_T=9,BIOPSY_T=1
    } Type;

    explicit Investigation(QObject *parent = 0);
    ~Investigation();

    void setDate(QDate arg);
    void setDate(int day, int month, int year);
    QDate getDate();

    void setTime(QTime arg);
    void setTime(int hour,int min);
    QTime getTime();

    void setType(Type arg);
    Type getType();

    void setDetails(QString arg);
    QString getDetails();

    void setReport(QString arg);
    QString getReport();

    QList<ID_TYPE> getLinkedTo();
    bool addLink(ID_TYPE arg);
    bool removeLink(ID_TYPE arg);

private:
     Type type;
signals:

public slots:

};

#endif // INVESTIGATION_H
