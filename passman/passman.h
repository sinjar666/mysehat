#ifndef PASSMAN_H
#define PASSMAN_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>
#include <QByteArray>
#include <QFile>
#include <QDataStream>
#include <QMap>
#include <QDebug>

class PassMan : public QObject
{
    Q_OBJECT
    QString pass_path;
    QMap<QString,QByteArray> pass_list;
public:
    explicit PassMan(QString path_a,QObject *parent = 0);
    void loadPassList();
    void addPass(QString username, QString password);
    bool checkPass(QString username, QString password);
    void savePassList();
    bool removePass(QString username);
    
signals:
    
public slots:
    
};

#endif // PASSMAN_H
