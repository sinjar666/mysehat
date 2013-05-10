#include "xappointment.h"

XAppointment::XAppointment(Appointment *arg,QString path,QObject *parent) :
    QObject(parent)
{
    obj=arg;
    filepath=path;
}
void XAppointment::readData()
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
    obj->setName(Item);
    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    //qDebug()<<Item;
    obj->setDate(QDate::fromString(Item));

    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
    obj->setTime(QTime::fromString(Item));

    tag=tag.nextSibling();
    QDomNodeList links=tag.childNodes();
    QDomNode link;int i=0;
    //qDebug()<<tag.toElement().tagName();
    while(!((link=links.item(i++)).isNull()))
    {
        //qDebug() << "should not be here";
        symptomComplained s;
        Item=link.childNodes().item(0).nodeValue();
        //qDebug()<<Item;
        s.link=Item;
        //QDomAttr temp;
        Item=link.toElement().attributeNode("date").value();
        //qDebug()<<Item;
        //Item=temp.value();
        //if(link.attributes().item(0).toAttr().specified())
        //    qDebug()<<"hell yes";
        s.date=QDate::fromString(Item);
        Item=link.toElement().attributeNode("duration").value();
        //qDebug()<<Item;
        s.duration=Item.toInt();
        obj->addSymptom(s);

    }
    tag=tag.nextSibling();
    links=tag.childNodes();
    i=0;
    //qDebug()<<tag.toElement().tagName();
    while(!((link=links.item(i++)).isNull()))
    {
        drugPrescribed s;
        Item=link.childNodes().item(0).nodeValue();
       // qDebug()<<Item;
        s.link=Item;
        Item=link.attributes().item(0).nodeValue();
        s.dosage=Item.toInt();
        Item=link.attributes().item(1).nodeValue();
        s.duration=Item.toInt();
        obj->addDrug(s);
    }
    tag=tag.nextSibling();
    links=tag.childNodes();
    i=0;
    //qDebug()<<tag.toElement().tagName();
    while(!((link=links.item(i++)).isNull()))
    {
        Item=link.childNodes().item(0).nodeValue();
        //qDebug()<<Item;
        surgeryAdvised temp;
        temp.link=Item;
        obj->addSurgery(temp);
    }
    tag=tag.nextSibling();
    links=tag.childNodes();
    i=0;
    //qDebug()<<tag.toElement().tagName();
    while(!((link=links.item(i++)).isNull()))
    {
        Item=link.childNodes().item(0).nodeValue();
        //qDebug()<<Item;
        investigationAdvised temp;
        temp.link=Item;
        obj->addInvestigation(temp);
    }
}
void XAppointment::saveData()
{
    //qDebug()<<"here.";
    QDomDocument XmlData;
    QDomElement root=XmlData.createElement("appointment");
    XmlData.appendChild(root);

    QDomElement temp=XmlData.createElement("name");
    root.appendChild(temp);
    QDomText temp2=XmlData.createTextNode(obj->getName());
    temp.appendChild(temp2);

    temp=XmlData.createElement("date");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getDate().toString());
    temp.appendChild(temp2);

    temp=XmlData.createElement("time");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getTime().toString());
    temp.appendChild(temp2);

    temp=XmlData.createElement("symptomcomplained");
    root.appendChild(temp);

    QList<symptomComplained> links=obj->getSymptom();
    //qDebug() <<"In xappoint:" << links.length();
    symptomComplained link1;
    foreach(link1,links)
    {
        QDomElement temp3=XmlData.createElement("symptom");
        temp.appendChild(temp3);
        temp2=XmlData.createTextNode(link1.link);
        temp3.setAttribute("date",link1.date.toString());
        temp3.setAttribute("duration",link1.duration);
        temp3.appendChild(temp2);
    }
    temp=XmlData.createElement("drugprescribed");
    root.appendChild(temp);

    QList<drugPrescribed> links2=obj->getDrug();
    drugPrescribed link2;

    foreach(link2,links2)
    {
        QDomElement temp3=XmlData.createElement("drug");
        temp.appendChild(temp3);
        temp2=XmlData.createTextNode(link2.link);
        temp3.setAttribute("dosage",QString::number(link2.dosage));
        temp3.setAttribute("duration",QString::number(link2.duration));
        temp3.appendChild(temp2);
    }

    temp=XmlData.createElement("surgeryadvised");
    root.appendChild(temp);

    QList<surgeryAdvised> links3=obj->getSurgery();
    surgeryAdvised link3;
    foreach(link3,links3)
    {
        QDomElement temp3=XmlData.createElement("link");
        temp.appendChild(temp3);
        temp2=XmlData.createTextNode(link3.link);
        temp3.appendChild(temp2);
    }

    temp=XmlData.createElement("investigationadvised");
    root.appendChild(temp);

    QList<investigationAdvised> links4=obj->getInvestigation();
    investigationAdvised link4;
    foreach(link4,links4)
    {
        QDomElement temp3=XmlData.createElement("link");
        temp.appendChild(temp3);
        temp2=XmlData.createTextNode(link4.link);
        temp3.appendChild(temp2);
    }
    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly))
        qDebug()<<"file not found";
    QTextStream out(&file);
    out<<XmlData.toString();
    file.close();
}
