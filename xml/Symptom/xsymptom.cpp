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

#include "xsymptom.h"

XSymptom::XSymptom(Symptom *arg,QString path,QObject *parent) :
    QObject(parent)
{
    obj=arg;
    filepath=path;
}
void XSymptom::readData()
{
    QDomDocument XmlData;
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly))
    {    qDebug()<<"file not found";
        file.close();
        return;
    }

    if(!XmlData.setContent(&file))  {
        qDebug()<<"error in file";
        return;
    }
    file.close();
    QDomNode tag=XmlData.firstChild();
    tag=tag.firstChild();
    QString Item;

    Item=tag.childNodes().item(0).nodeValue();
    //qDebug()<<Item;
    obj->setDescription(Item);
    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setCharacteristics(Item);
    //qDebug()<<Item;

    tag=tag.nextSibling();
    QDomNodeList links=tag.childNodes();
    QDomNode link;int i=0;
    //qDebug()<<tag.toElement().tagName();
    while(!((link=links.item(i++)).isNull()))
    {
        Item=link.childNodes().item(0).nodeValue();
        //qDebug()<<Item;

        obj->addLink(Item);
    }
}
void XSymptom::saveData()
{
    QDomDocument XmlData;
    QDomElement root=XmlData.createElement("symptom");
    XmlData.appendChild(root);

    QDomElement temp=XmlData.createElement("description");
    root.appendChild(temp);
    QDomText temp2=XmlData.createTextNode(obj->getDescription());
    temp.appendChild(temp2);

    temp=XmlData.createElement("characteristics");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getCharacteristics());
    temp.appendChild(temp2);

    QList<QString> links=obj->getLinkedTo();

    temp=XmlData.createElement("linkedto");
    root.appendChild(temp);

    QString link;
    foreach(link,links)
    {
        QDomElement temp3=XmlData.createElement("link");
        temp.appendChild(temp3);
        temp2=XmlData.createTextNode(link);
        temp3.appendChild(temp2);
    }
    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly))
        qDebug()<<"file not found";
    QTextStream out(&file);
    out<<XmlData.toString();
    file.close();
}
