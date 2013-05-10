#ifndef ADDITEMBUTTON_H
#define ADDITEMBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QImage>

class AddItemButton : public QPushButton
{
    Q_OBJECT
    QVBoxLayout *lay;
    QLabel *icon_l,*name_l;
    QStringList names,iconpaths;
public:
    typedef enum    {
        APPOINTMENT_T = 0,
        SYMPTOM_T = 1,
        INVESTIGATION_T = 2,
        SURGERY_T = 3,
        DRUG_T = 4,
        ALLERGEN_T=5,
        VACCINE_T=6,
        FAMILYHISTORY_T=7
    } ItemType;

    explicit AddItemButton(ItemType type,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ADDITEMBUTTON_H
