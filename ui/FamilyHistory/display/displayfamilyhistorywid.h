#ifndef DISPLAYFAMILYHISTORYWID_H
#define DISPLAYFAMILYHISTORYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "model/familyhistory.h"

class DisplayFamilyHistoryWid : public QWidget
{
    Q_OBJECT
    FamilyHistory *model;
    QGridLayout *lay;
    QLabel *name_l,*name_e,*members_l,*members_e;

public:
    explicit DisplayFamilyHistoryWid(FamilyHistory *arg,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DISPLAYFAMILYHISTORYWID_H
