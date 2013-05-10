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
