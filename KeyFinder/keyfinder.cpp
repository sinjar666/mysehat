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

