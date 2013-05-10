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

#include "passman.h"

PassMan::PassMan(QString path_a, QObject *parent) :
    QObject(parent)
{
    pass_path=path_a;
}

void PassMan::loadPassList()    {
    QFile fil(pass_path);
    if(!fil.open(QIODevice::ReadOnly))  {
        qDebug() << "Passman::Passwd file not present creating it...";
        if(!fil.open(QIODevice::WriteOnly))  {
            qDebug() << "Passman::Readonly fs. File not created";
        }
    }
    else    {
        pass_list.clear();
        QDataStream stream(&fil);
        stream>>pass_list;
    }
    fil.close();
}

void PassMan::savePassList()    {
    QFile fil(pass_path);
    if(!fil.open(QIODevice::WriteOnly | QIODevice::Truncate))   {
        qDebug() << "Passman:Unable to truncate the file.";
    }
    else    {
        QDataStream stream(&fil);
        stream << pass_list;
    }
    fil.close();
}

void PassMan::addPass(QString username, QString password)   {
    QByteArray password_,hash_stg1,hash_stg2,hash_final;
    password_ = password.toLocal8Bit();
    //Order is sha1->salt with username+"!QASW@"->md5->salt with j5u9t!@=03uAA9!@*3 -> sha1
    hash_stg1 = QCryptographicHash::hash(password_,QCryptographicHash::Sha1);
    hash_stg1.append(username.toLocal8Bit());
    hash_stg1.append("!QASW@");
    hash_stg2 = QCryptographicHash::hash(hash_stg1,QCryptographicHash::Md5);
    hash_stg2.append("j5u9t!@=03uAA9!@*3");
    hash_final = QCryptographicHash::hash(hash_stg2,QCryptographicHash::Sha1);
    hash_final=hash_final.toHex();
    //qDebug() << hash_final;
    if(!pass_list.contains(username))   {
        pass_list.insert(username,hash_final);
        qDebug() << "Passman:Password added.";
    }
    else    {
        qDebug() << "Passman:User is already present";
    }
}

bool PassMan::checkPass(QString username, QString password) {
    QByteArray password_,hash_stg1,hash_stg2,hash_final,hash_db;
    password_ = password.toLocal8Bit();
    //Order is sha1->salt with username+"!QASW@"->md5->salt with j5u9t!@=03uAA9!@*3 -> sha1
    hash_stg1 = QCryptographicHash::hash(password_,QCryptographicHash::Sha1);
    hash_stg1.append(username.toLocal8Bit());
    hash_stg1.append("!QASW@");
    hash_stg2 = QCryptographicHash::hash(hash_stg1,QCryptographicHash::Md5);
    hash_stg2.append("j5u9t!@=03uAA9!@*3");
    hash_final = QCryptographicHash::hash(hash_stg2,QCryptographicHash::Sha1);
    hash_final=hash_final.toHex();

    //qDebug() << hash_final;
    hash_db = pass_list.value(username);
    if(hash_final == hash_db)
        return true;
    else return false;
}

bool PassMan::removePass(QString username)  {
    if(pass_list.remove(username)>0)
        return true;
    else return false;
}
