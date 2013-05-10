#include "displayallergenwid.h"

DisplayAllergenWid::DisplayAllergenWid(Allergen *arg, QWidget *parent) :
    QWidget(parent)
{
    model = arg;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Name"));
    name_e = new QLabel(model->getName());
    type_l = new QLabel(tr("Type"));
    QStringList types;
    types << "Drug" << "Natural" << "Synthetic" << "Food";
    type_e = new QLabel(types[(int)model->getType()]);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(type_l,1,0);
    lay->addWidget(type_e,1,1);
}
