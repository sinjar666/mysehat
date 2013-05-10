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

#include "keyfinder.h"

KeyFinder::KeyFinder(QString arg,QObject *parent) :
    QObject(parent)
{
    text = arg;
}

QStringList KeyFinder::generate()
{
    QFile *fil = new QFile(":/words/noise");
    if(!fil->open(QIODevice::ReadOnly))
        qDebug()<< "keyfinder::file not found.";

    QStringList total;
    QStringList bad;
    QString content;
    QTextStream stream(fil);
    stream >> content;
    //qDebug()<<content;
    bad = content.split(",",QString::SkipEmptyParts);
    total = text.split(" ",QString::SkipEmptyParts);
    QStringList::iterator i;
    for(i=total.begin();i!=total.end();++i) {
        (*i)=(*i).toLower();
    }
    for(i=bad.begin();i!=bad.end();++i)  {
        //qDebug()<<*i;
        total.removeAll((*i));
    }
    //delete content;
    //qDebug() << "keywords: " << total;
    return total;
}

