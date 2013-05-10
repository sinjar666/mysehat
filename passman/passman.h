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

#ifndef PASSMAN_H
#define PASSMAN_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>
#include <QByteArray>
#include <QFile>
#include <QDataStream>
#include <QMap>
#include <QDebug>

class PassMan : public QObject
{
    Q_OBJECT
    QString pass_path;
    QMap<QString,QByteArray> pass_list;
public:
    explicit PassMan(QString path_a,QObject *parent = 0);
    void loadPassList();
    void addPass(QString username, QString password);
    bool checkPass(QString username, QString password);
    void savePassList();
    bool removePass(QString username);
    
signals:
    
public slots:
    
};

#endif // PASSMAN_H
