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

#ifndef XDRUG_H
#define XDRUG_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "model/drug.h"

class XDrug : public QObject
{
    Q_OBJECT
    Drug *obj;
    QString filepath;

public:
    explicit XDrug(Drug *arg,QString path,QObject *parent = 0);
    void readData();
    void saveData();

signals:

public slots:

};

#endif // XDRUG_H
