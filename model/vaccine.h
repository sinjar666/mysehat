#ifndef VACCINE_H
#define VACCINE_H

#include <QObject>
#include <QString>
#include <QDate>

#define ID_TYPE QString

class Vaccine : public QObject
{
    Q_OBJECT
    ID_TYPE *id;
    QString *name;
    quint16 validity; //in months, 0 indicates lifelong
    QDate *date;

public:
    explicit Vaccine(QObject *parent = 0);
    ~Vaccine();
    void setName(QString arg);
    QString getName();
    void setValidity(quint16 arg);
    quint16 getValidity();
    void setDate(QDate arg);
    void setDate(int day, int month, int year);
    QDate getDate();

signals:

public slots:

};

#endif // VACCINE_H
