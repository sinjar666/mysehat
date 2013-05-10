#include "config.h"

Config::Config(QString path,QObject *parent) :
    QObject(parent)
{
    filepath=path;
    //path.append("config.xml");
    QFile file_t(filepath+"config.xml");
    if(!file_t.open(QIODevice::ReadOnly))
    {   //file_t.close();
        file_t.open(QIODevice::WriteOnly);
        QDomDocument XmlData;
        QDomElement config_tag=XmlData.createElement("config");
        QDomElement id_tag=XmlData.createElement("id");
        QDomElement tag=XmlData.createElement("symptom");

        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        tag=XmlData.createElement("appointment");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        tag=XmlData.createElement("allergen");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        tag=XmlData.createElement("drug");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        tag=XmlData.createElement("investigation");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        tag=XmlData.createElement("surgery");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        tag=XmlData.createElement("vaccine");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        //config_tag.appendChild(id_tag);
        tag=XmlData.createElement("familyhistory");
        tag.appendChild(XmlData.createTextNode("0"));
        id_tag.appendChild(tag);
        config_tag.appendChild(id_tag);

        id_tag=XmlData.createElement("users");
        config_tag.appendChild(id_tag);
        XmlData.appendChild(config_tag);

        QTextStream out(&file_t);
        out<<XmlData.toString();
        file_t.close();
    }
    file_t.close();
    //qDebug("1h2345");
}
void Config::adduser(QString user)
{
    QFile file(filepath+"config.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("file not found");
        return;
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))
    {
        qDebug()<<"error in file";
        return;
    }
    file.close();
    //qDebug("stage one.");
    user.replace(QString(" "),QString("_"));
    QDomElement tag=XmlData.firstChild().toElement();
    QDomNodeList id1=tag.elementsByTagName("users");
    QDomNodeList list_user=id1.item(0).childNodes();
    //QDomNode user_node;
    int found=0;uint i=0;
    while(i<list_user.length())
    {
        if(list_user.item(i).toElement().tagName()==user)
        {
            qDebug()<<"user is already present";
            found=1;
            break;
        }
        i++;
    }
    //qDebug("stg two");

    if(found==0)
    {
        QDomElement name=XmlData.createElement(user);
        QDomText text=XmlData.createTextNode(filepath+user+"/");
        name.appendChild(text);
        id1.item(0).appendChild(name);
    }
    found=0;
    QFile file1(filepath+"config.xml");
    if(!file1.open(QIODevice::WriteOnly))
    {
        qDebug()<<"cant write the file";
        return;
    }
    QTextStream out(&file1);
    out<<XmlData.toString();
    file1.close();
    //qDebug("stage three");

}
void Config::deluser(QString user)
{
    QFile file(filepath+"config.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("file not found");
        return;
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))
    {
        qDebug()<<"error in file";
        return;
    }
    file.close();

    QDomElement tag=XmlData.firstChild().toElement();
    QDomNodeList id1=tag.elementsByTagName("users");
    QDomNodeList list_users=id1.item(0).childNodes();
    //QDomNode user1;
    int found=0;uint i=0;

    while(i<list_users.length())
    {
        if(list_users.item(i).toElement().tagName()==user)
        {
            id1.item(0).removeChild(list_users.item(i));
            found=1;
        }
        i++;
    }
    if(found==0)
        qDebug()<<"no user to delete";
    found=0;
    QFile file1(filepath+"config.xml");
    if(!file1.open(QIODevice::WriteOnly))
    {
        qDebug()<<"cant write the file";
        return;
    }
    QTextStream out(&file1);
    out<<XmlData.toString();
    file1.close();
}
QString Config::readData(QString option)
{
    QFile file(filepath+"config.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("file not found");
        return QString();
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))
    {
        qDebug("error in file");
        return QString();
    }
    file.close();
    QDomElement tag=XmlData.firstChild().toElement();
    QDomNodeList list_id=tag.elementsByTagName("id");
    QDomNodeList id_option=list_id.item(0).childNodes();
    QDomNode id_tag;uint i=0;QString name;
    while(i<id_option.length())
    {
        id_tag=id_option.item(i);
        if(id_tag.toElement().tagName()==option)
        {   //qDebug()<<id_tag.toElement().tagName();
            name=id_tag.toElement().text();
            //return name;
            //qDebug()<<name;
            break;
        }
        i++;
    }
    return name;
}
void Config::writeData(QString option,QString value)
{
    QFile file(filepath+"config.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("file not found");
        return;
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))
    {
        qDebug("error in file");
        return;
    }
    file.close();
    QDomElement tag=XmlData.firstChild().toElement();
    QDomNodeList list_id=tag.elementsByTagName("id");
    QDomNodeList id_option=list_id.item(0).childNodes();
    QDomNode id_tag;uint i=0;
    while(i<id_option.length())
    {
        //qDebug() << id_option.item(i).toElement().tagName();
        id_tag=id_option.item(i);
        if(id_tag.toElement().tagName()==option)
        {
            QDomText text=XmlData.createTextNode(value);
            id_tag.replaceChild(text,id_tag.childNodes().item(0));
        }
        i++;
    }
    QFile file1(filepath+"config.xml");
    if(!file1.open(QIODevice::WriteOnly))
    {
        qDebug()<<"cant write the file";
        return;
    }
    QTextStream out(&file1);
    out<<XmlData.toString();
    file1.close();
}
QStringList Config::userlist()
{
    QFile file(filepath+"config.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("file not found");
        //return QStringList();
    }
    QDomDocument XmlData;
    if(!XmlData.setContent(&file))
    {
        qDebug("error in file");
        //return QStringList();
    }
    file.close();
    QDomElement tag=XmlData.firstChild().toElement();
    QDomNodeList list_user=tag.elementsByTagName("users");
    QDomNodeList id_option=list_user.item(0).childNodes();
    uint i=0;
    QStringList list1;
    QDomNode user;QString name;
    while(i<id_option.length())
    {
        user=id_option.item(i);
        name=user.toElement().tagName();
        list1<<name;
        i++;
    }
   return list1;
}
