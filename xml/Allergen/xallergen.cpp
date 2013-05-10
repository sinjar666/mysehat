#include "xallergen.h"

XAllergen::XAllergen(Allergen *arg, QString path, QObject *parent) :
    QObject(parent)
{
    obj=arg;
    filepath=path;
}

void XAllergen::readData()
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
    //qDebug()<<Item;
    if(Item=="0"){
        obj->setType(Allergen::drug_t);
    }
    else if(Item=="1"){
        obj->setType(Allergen::natural_t);
    }
    else if(Item=="2"){
        obj->setType(Allergen::synthetic_t);
    }
    else{
        obj->setType(Allergen::food_t);
    }
    tag=tag.nextSibling();
    Item=tag.childNodes().item(0).nodeValue();
   // qDebug()<<Item;
    obj->setDate(QDate::fromString(Item));
    tag=tag.nextSibling();
    if(obj->getType()==Allergen::drug_t){
        Item=tag.childNodes().item(0).nodeValue();
        //qDebug()<<Item;
        obj->setDrug(Item);
    }

}
void XAllergen::saveData()
{
    QDomDocument XmlData;
    QDomElement root=XmlData.createElement("Allergen");
    XmlData.appendChild(root);

    QDomElement temp=XmlData.createElement("name");
    root.appendChild(temp);
    QDomText temp2=XmlData.createTextNode(obj->getName());
    temp.appendChild(temp2);

    temp=XmlData.createElement("type");
    root.appendChild(temp);
    if(obj->getType()==0)
       temp2=XmlData.createTextNode("0");
    else if(obj->getType()==1)
       temp2=XmlData.createTextNode("1");
    else if(obj->getType()==2)
       temp2=XmlData.createTextNode("2");
    else
       temp2=XmlData.createTextNode("3");
    temp.appendChild(temp2);

    temp=XmlData.createElement("date");
    root.appendChild(temp);
    temp2=XmlData.createTextNode(obj->getDate().toString());
    temp.appendChild(temp2);

    temp=XmlData.createElement("drugid");
    root.appendChild(temp);
    if(obj->getType()==Allergen::drug_t)
        temp2=XmlData.createTextNode(obj->getDrug());
    else
        temp2=XmlData.createTextNode("n/a");
    temp.appendChild(temp2);

    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly))
        qDebug()<<"file not found";
    QTextStream out(&file);
    out<<XmlData.toString();
    file.close();
}



