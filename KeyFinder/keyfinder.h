#ifndef KEYFINDER_H
#define KEYFINDER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class KeyFinder : public QObject
{
    Q_OBJECT
    QString text;
    QStringList keywords;
public:
    explicit KeyFinder(QString arg,QObject *parent = 0);
    QStringList generate();

signals:

public slots:

};

#endif // KEYFINDER_H
