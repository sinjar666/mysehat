#ifndef DISPLAYALLERGENWID_H
#define DISPLAYALLERGENWID_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "model/allergen.h"

class DisplayAllergenWid : public QWidget
{
    Q_OBJECT
    Allergen *model;
    QLabel *name_l,*name_e,*type_l,*type_e;
    QGridLayout *lay;
public:
    explicit DisplayAllergenWid(Allergen *arg,QWidget *parent = 0);

    
signals:
    
public slots:
    
};

#endif // DISPLAYALLERGENWID_H
