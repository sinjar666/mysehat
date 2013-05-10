#ifndef SURGERY_H
#define SURGERY_H

#include <QObject>
#include <QString>
#include <QDate>

#define ID_TYPE QString
class Surgery : public QObject
{
    Q_OBJECT
    ID_TYPE *id;
    QString *details;
    QDate *date;
    QList<ID_TYPE> *linkedTo;
public:
    explicit Surgery(QObject *parent = 0);
    ~Surgery();

    void setDetails(QString arg);
    QString getDetails();
    void setDate(QDate arg);
    void setDate(int day, int month, int year);
    QDate getDate();
    QList<ID_TYPE> getLinkedTo();
    bool addLink(ID_TYPE arg);
    bool removeLink(ID_TYPE arg);

signals:

public slots:

};

#endif // SURGERY_H
