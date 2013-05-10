#include "additembutton.h"

AddItemButton::AddItemButton(ItemType type, QWidget *parent) :
    QPushButton(parent)
{
    //setMinimumSize(200,200);

    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    names << "Appointment" << "Symptom" << "Investigation" << "Surgery" << "Drug" << "Allergen" << "Vaccine" << "Family History";
    iconpaths << ":/icons/appointment.jpg" << ":/icons/symptom.xpm" << ":/icons/investigation.xpm"
              << ":/icons/surgery.xpm" << ":/icons/drug.xpm" << ":/icons/allergen.xpm" << ":/icons/vaccine.xpm"
              << ":/icons/family.xpm";
    lay = new QVBoxLayout(this);
    icon_l = new QLabel();
    icon_l->setPixmap(QPixmap::fromImage(QImage(iconpaths[(int)type])).scaled(150,150));
    name_l = new QLabel(names[(int)type]);
    lay->addWidget(icon_l);
    lay->addWidget(name_l);
}
