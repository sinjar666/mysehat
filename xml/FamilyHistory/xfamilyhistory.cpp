#include "xfamilyhistory.h"

XFamilyHistory::XFamilyHistory(FamilyHistory *arg,QString path,QObject *parent) :
    QObject(parent)
{
    obj=arg;
    filepath=path;
}

void XFamilyHistory::readData()
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
    //qDebug()<<tag.toElement().tagName();
    tag=tag.firstChild();
    QString Item;
    Item=tag.childNodes().item(0).nodeValue();
    //qDebug()<<Item;
    obj->setName(Item);
    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setMembers(Item.toUInt());

}
void XFamilyHistory::saveData()
{
    QDomDocument XmlData;
    QDomElement root=XmlData.createElement("familyhistory");
    XmlData.appendChild(root);

    QDomElement temp=XmlData.createElement("name");
    root.appendChild(temp);
    QDomText temp2=XmlData.createTextNode(obj->getName());
    temp.appendChild(temp2);

    temp=XmlData.createElement("members");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(QString::number(obj->getMembers()));
    temp.appendChild(temp2);

    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly))
        qDebug()<<"file not found";
    QTextStream out(&file);
    out<<XmlData.toString();
    file.close();
}
