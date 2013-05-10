#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDomNodeList>
#include <QDomNode>
#include <QDomElement>
#include <QDomText>

class Config : public QObject
{
    Q_OBJECT
    QString filepath;
public:
    explicit Config(QString path,QObject *parent = 0);
    void adduser(QString user);
    void deluser(QString user);
    QString readData(QString option);
    void writeData(QString option,QString value);
    QStringList userlist();
signals:

public slots:

};

#endif // CONFIG_H
