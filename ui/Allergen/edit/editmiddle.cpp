#include "editmiddle.h"

EditMiddle::EditMiddle(QWidget *parent) :
    QWidget(parent)
{
    label1=new QLabel("Type");
    box=new QComboBox();
    types = new QStringList();
    *types <<"Drug" <<"Natural" <<"Synthetic" <<"Food" ;
    box->addItems(*types);
    h=new QHBoxLayout(this);
    h->addWidget(label1);
    h->addWidget(box);
}

Allergen::A_type EditMiddle::getType()  {
    switch(box->currentIndex())  {
    case 0:
        return Allergen::drug_t;
    case 1:
        return Allergen::natural_t;
    case 2:
        return Allergen::synthetic_t;
    case 3:
        return Allergen::food_t;
    }
}

void EditMiddle::setType(Allergen::A_type type) {
    switch(type)    {
    case Allergen::drug_t:
        box->setCurrentIndex(0);
        break;
    case Allergen::natural_t:
        box->setCurrentIndex(1);
        break;
    case Allergen::synthetic_t:
        box->setCurrentIndex(2);
        break;
    case Allergen::food_t:
        box->setCurrentIndex(3);
        break;
    }
}
