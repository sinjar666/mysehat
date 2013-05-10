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

#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDomNodeList>
#include <QDomNode>
#include <QDomElement>
#include <QDomText>

class Config : public QObject
{
    Q_OBJECT
    QString filepath;
public:
    explicit Config(QString path,QObject *parent = 0);
    void adduser(QString user);
    void deluser(QString user);
    QString readData(QString option);
    void writeData(QString option,QString value);
    QStringList userlist();
signals:

public slots:

};

#endif // CONFIG_H
