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

#ifndef XDISEASE_H
#define XDISEASE_H

#include <QObject>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QTextStream>
#include <QDomAttr>
#include <QString>
#include <QStringList>

class XDisease : public QObject
{
    Q_OBJECT
    QString filepath;
public:
    explicit XDisease(QString path,QObject *parent = 0);
    QStringList getdname();
    QStringList getdpath(QString dis);
    void adddisease(QString dis,QString fpath);
    void deletedisease(QString dis,QString fpath);
signals:

public slots:

};

#endif // XDISEASE_H
