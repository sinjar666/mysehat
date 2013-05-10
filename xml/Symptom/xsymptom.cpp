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
