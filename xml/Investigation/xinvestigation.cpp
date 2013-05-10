#include "xinvestigation.h"

XInvestigation::XInvestigation(Investigation *arg,QString path,QObject *parent) :
    QObject(parent)
{
    obj=arg;
    filepath=path;
}
void XInvestigation::readData()
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
    obj->setDate(QDate::fromString(Item));

    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setTime(QTime::fromString(Item));
    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setType((Investigation::Type)Item.toInt());
    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setDetails(Item);

    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setReport(Item);

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
void XInvestigation::saveData()
{
    //qDebug()<<"here.";
    QDomDocument XmlData;
    QDomElement root=XmlData.createElement("investigation");
    XmlData.appendChild(root);

    QDomElement temp=XmlData.createElement("date");
    root.appendChild(temp);
    QDomText temp2=XmlData.createTextNode(obj->getDate().toString());
    temp.appendChild(temp2);

    temp=XmlData.createElement("time");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getTime().toString());
    temp.appendChild(temp2);

    temp=XmlData.createElement("type");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(QString::number(obj->getType()));
    temp.appendChild(temp2);

    temp=XmlData.createElement("details");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getDetails());
    temp.appendChild(temp2);

    temp=XmlData.createElement("report");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getReport());
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
