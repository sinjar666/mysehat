#include "xdisease.h"

XDisease::XDisease(QString path,QObject *parent) :
    QObject(parent)
{
    filepath=path;
    filepath.append("disease.xml");
    QFile file_t(filepath);
    if(!file_t.open(QIODevice::ReadOnly))
    {   file_t.close();
        file_t.open(QIODevice::WriteOnly);
        QDomDocument XmlData;
        QDomElement disease_tag=XmlData.createElement("diseases");
        XmlData.appendChild(disease_tag);

        QTextStream out(&file_t);
        out<<XmlData.toString();
        file_t.close();
    }
	
}
void XDisease::adddisease(QString dis,QString fpath)
{
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly))
    {    qDebug()<<"file not found";
        //file.open(QIODevice::Truncate | QIODevice::WriteOnly);
    }
    QDomDocument XmlData;

    if(!XmlData.setContent(&file))  {
        qDebug()<<"error in file";
        return;
    }
    file.close();
    dis.replace(QString(" "),QString("_"));
    QDomNode tag;
    QDomNodeList Item;
    tag=XmlData.firstChild();
    Item=tag.toElement().elementsByTagName(dis);
    if(Item.isEmpty())
    {
        QDomElement new1=XmlData.createElement(dis);
        QDomElement file=XmlData.createElement("file");
        QDomText text=XmlData.createTextNode(fpath);
        file.appendChild(text);
        new1.appendChild(file);
        tag.appendChild(new1);
    }
    else
    {
       QDomNode t;
       t=Item.item(0);
       QDomElement file=XmlData.createElement("file");
       QDomText text=XmlData.createTextNode(fpath);
       file.appendChild(text);
       t.toElement().appendChild(file);
    }
    QFile file1(filepath);
    if(!file1.open(QIODevice::WriteOnly | QIODevice::Truncate))
        qDebug()<<"file not found";
    QTextStream out(&file1);
    out<<XmlData.toString();
    file1.close();
}
QStringList XDisease::getdname()
{
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly))
    {    qDebug()<<"file not found";
        //file.open(QIODevice::Truncate | QIODevice::WriteOnly);
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))  {
        qDebug()<<"error in file";
        return QStringList();
    }
    file.close();
    QDomNode tag;
    QDomNodeList Item;QStringList list;
    tag=XmlData.firstChild();
    Item=tag.childNodes();
    QString name;int i=0;
    while(i<Item.length())
    {
        tag=Item.item(i);
        name=tag.toElement().tagName();
        list << name;
        i++;
    }
    //return Item;
    return list;
}
QStringList XDisease::getdpath(QString dis)
{
    QDomDocument XmlData;
    QStringList list;
    QDomNodeList Item,Item2;
    QDomElement tag;
    QString name;
    tag=XmlData.firstChild().toElement();
    Item2=tag.elementsByTagName(dis);
    Item=Item2.item(0).childNodes();
    int i=0;
    while(i<Item.length())
    {
        tag=Item.item(i).toElement();
        name=tag.childNodes().item(0).nodeValue();
        list <<name;
        i++;
    }
    return list;
}
void XDisease::deletedisease(QString dis,QString fpath)
{
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly))
    {    qDebug()<<"file not found";
        //file.open(QIODevice::Truncate | QIODevice::WriteOnly);
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))  {
        qDebug()<<"error in file";
        return ;
    }
    file.close();
    QDomNode tag,tag2=XmlData.firstChild();
    QDomNodeList Items=tag2.toElement().elementsByTagName(dis);
    QString name;
    QDomNodeList Items2=Items.item(0).childNodes();
    int i=0;
    while(i<Items2.length())
    {
        tag=Items2.item(i);
        name=tag.childNodes().item(0).nodeValue();
        if(name==fpath)
        {
           Items.item(0).removeChild(Items2.item(i));
        }
        i++;
    }
    if(!Items.item(0).hasChildNodes())
    {
        tag2.removeChild(Items.item(0));
    }
    QFile file1(filepath);
    if(!file1.open(QIODevice::WriteOnly | QIODevice::Truncate))
        qDebug()<<"file not found";
    QTextStream out(&file1);
    out<<XmlData.toString();
    file1.close();
}
