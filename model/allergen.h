#ifndef ALLERGEN_H
#define ALLERGEN_H

#include <QObject>
#include <QDate>

#define ID_TYPE QString



class Allergen : public QObject
{
    Q_OBJECT
    QString *name,*drug_id;
    QDate *date; //When it was diagnosed

public:
    typedef enum    {
        drug_t,natural_t,synthetic_t,food_t
    } A_type;

    explicit Allergen(QObject *parent = 0);
    ~Allergen();

    void setName(QString arg);
    QString getName();

    void setType(A_type arg);
    A_type getType();

    void setDrug(QString arg);
    QString getDrug();

    void setDate(int day,int month,int year);
    void setDate(QDate arg);
    QDate getDate();

private:
     A_type type;

signals:

public slots:

};

#endif // ALLERGEN_H
