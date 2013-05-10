#ifndef VACCINEDETAILSWID_H
#define VACCINEDETAILSWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>

class VaccineDetailsWid : public QWidget
{
    Q_OBJECT
    QLabel *name_l,*validity_l,*date_l;
    QLineEdit *name_e;
    QDateEdit *date_e;
    QSpinBox *validity_e;
    QGridLayout *lay;
public:
    explicit VaccineDetailsWid(QWidget *parent = 0);
    QString getName();
    quint16 getValidity();
    QDate getDate();
    
signals:
    
public slots:
    void resetAll();
    
};

#endif // VACCINEDETAILSWID_H
