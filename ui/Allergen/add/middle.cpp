#include "middle.h"

Middle::Middle(QWidget *parent) :
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

Allergen::A_type Middle::getType()  {
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
