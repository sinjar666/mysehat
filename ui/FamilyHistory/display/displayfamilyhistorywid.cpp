#include "displayfamilyhistorywid.h"

DisplayFamilyHistoryWid::DisplayFamilyHistoryWid(FamilyHistory *arg, QWidget *parent) :
    QWidget(parent)
{
    model=arg;
    lay = new QGridLayout(this);
    name_l = new QLabel(tr("Name of Disease:"));
    name_e = new QLabel(model->getName());
    members_l = new QLabel(tr("Members:"));

    QString txt;
    if(model->isBrother()) txt+="Brother\n";
    if(model->isFather()) txt+="Father\n";
    if(model->isGrandfather()) txt += "Grandfather\n";
    if(model->isGrandmother()) txt += "Grandmother\n";
    if(model->isMother()) txt += "Mother\n";
    if(model->isSister()) txt += "Sister";
    members_e = new QLabel(txt);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(members_l,1,0);
    lay->addWidget(members_e,1,1);
}
