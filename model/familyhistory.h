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

#ifndef FAMILYHISTORY_H
#define FAMILYHISTORY_H

#include <QObject>
#include <QString>

#define ID_TYPE QString
class FamilyHistory : public QObject
{
    Q_OBJECT

    ID_TYPE *id;
    QString *name; //Name of disease
    quint8 members;
public:
    typedef enum    {
        MOTHER_T = 1 << 0,
        FATHER_T = 1 << 1,
        BROTHER_T = 1 << 2,
        SISTER_T = 1 << 3,
        GRANDFATHER_T = 1 << 4,
        GRANDMOTHER_T = 1 << 5
    } Members;
    explicit FamilyHistory(QObject *parent = 0);
    ~FamilyHistory();
    void setName(QString arg);
    QString getName();
    quint8 getMembers();
    void setMembers(quint8 arg);

    void addMember(Members arg);
    bool isMother();
    bool isFather();
    bool isBrother();
    bool isSister();
    bool isGrandfather();
    bool isGrandmother();
signals:

public slots:

};

#endif // FAMILYHISTORY_H
