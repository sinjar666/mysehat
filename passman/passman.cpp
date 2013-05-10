#include "passman.h"

PassMan::PassMan(QString path_a, QObject *parent) :
    QObject(parent)
{
    pass_path=path_a;
}

void PassMan::loadPassList()    {
    QFile fil(pass_path);
    if(!fil.open(QIODevice::ReadOnly))  {
        qDebug() << "Passman::Passwd file not present creating it...";
        if(!fil.open(QIODevice::WriteOnly))  {
            qDebug() << "Passman::Readonly fs. File not created";
        }
    }
    else    {
        pass_list.clear();
        QDataStream stream(&fil);
        stream>>pass_list;
    }
    fil.close();
}

void PassMan::savePassList()    {
    QFile fil(pass_path);
    if(!fil.open(QIODevice::WriteOnly | QIODevice::Truncate))   {
        qDebug() << "Passman:Unable to truncate the file.";
    }
    else    {
        QDataStream stream(&fil);
        stream << pass_list;
    }
    fil.close();
}

void PassMan::addPass(QString username, QString password)   {
    QByteArray password_,hash_stg1,hash_stg2,hash_final;
    password_ = password.toLocal8Bit();
    //Order is sha1->salt with username+"!QASW@"->md5->salt with j5u9t!@=03uAA9!@*3 -> sha1
    hash_stg1 = QCryptographicHash::hash(password_,QCryptographicHash::Sha1);
    hash_stg1.append(username.toLocal8Bit());
    hash_stg1.append("!QASW@");
    hash_stg2 = QCryptographicHash::hash(hash_stg1,QCryptographicHash::Md5);
    hash_stg2.append("j5u9t!@=03uAA9!@*3");
    hash_final = QCryptographicHash::hash(hash_stg2,QCryptographicHash::Sha1);
    hash_final=hash_final.toHex();
    //qDebug() << hash_final;
    if(!pass_list.contains(username))   {
        pass_list.insert(username,hash_final);
        qDebug() << "Passman:Password added.";
    }
    else    {
        qDebug() << "Passman:User is already present";
    }
}

bool PassMan::checkPass(QString username, QString password) {
    QByteArray password_,hash_stg1,hash_stg2,hash_final,hash_db;
    password_ = password.toLocal8Bit();
    //Order is sha1->salt with username+"!QASW@"->md5->salt with j5u9t!@=03uAA9!@*3 -> sha1
    hash_stg1 = QCryptographicHash::hash(password_,QCryptographicHash::Sha1);
    hash_stg1.append(username.toLocal8Bit());
    hash_stg1.append("!QASW@");
    hash_stg2 = QCryptographicHash::hash(hash_stg1,QCryptographicHash::Md5);
    hash_stg2.append("j5u9t!@=03uAA9!@*3");
    hash_final = QCryptographicHash::hash(hash_stg2,QCryptographicHash::Sha1);
    hash_final=hash_final.toHex();

    //qDebug() << hash_final;
    hash_db = pass_list.value(username);
    if(hash_final == hash_db)
        return true;
    else return false;
}

bool PassMan::removePass(QString username)  {
    if(pass_list.remove(username)>0)
        return true;
    else return false;
}
