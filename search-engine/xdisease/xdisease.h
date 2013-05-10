#ifndef XDISEASE_H
#define XDISEASE_H

#include <QObject>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QTextStream>
#include <QDomAttr>
#include <QString>
#include <QStringList>

class XDisease : public QObject
{
    Q_OBJECT
    QString filepath;
public:
    explicit XDisease(QString path,QObject *parent = 0);
    QStringList getdname();
    QStringList getdpath(QString dis);
    void adddisease(QString dis,QString fpath);
    void deletedisease(QString dis,QString fpath);
signals:

public slots:

};

#endif // XDISEASE_H
