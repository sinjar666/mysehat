#ifndef ITEMBUTTON_H
#define ITEMBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QListWidget>
#include <QMenu>

#include "widgets/itemwidget.h"
#include "engine/engine.h"
#include "engine/indexitem.h"
#include "linkdiseasedialog.h"

#include "ui/Allergen/edit/editallergenwid.h"
#include "ui/Appointment/edit/editappointmentwid.h"
#include "ui/Drug/edit/editdrugwid.h"
#include "ui/FamilyHistory/edit/editfamilyhistorywid.h"
#include "ui/Investigation/edit/editinvestigationwid.h"
#include "ui/Surgery/edit/editsurgerywid.h"
#include "ui/Symptom/edit/editsymptomwid.h"
#include "ui/Vaccine/edit/editvaccinewid.h"

class ItemButton : public QPushButton
{
    Q_OBJECT
public:
    enum ItemType   {
        Appointment=0,
        Symptom=1,
        Allergen=2,
        Drug=3,
        Investigation=4,
        Surgery=5,
        FamilyHistory=6,
        Vaccine=7
    };

    enum InvestigationType  {
        Angiography=0,
        Biopsy=1,
        BloodTest=2,
        Colonoscopy=3,
        CT=4,
        ECG=5,
        Echo=6,
        EEG=7,
        Endoscopy=8,
        FNAC=9,
        Funduscopy=10,
        HalterTest=11,
        MRI=12,
        Sputum=13,
        StoolTest=14,
        ThroatSwab=15,
        Treadmill=16,
        UrineTest=17,
        USG=18,
        Xray=19,
        Other=20
    };


    ItemButton(QString uroot_a,Engine *arg,IndexItem *i,QString key_a,ItemButton::ItemType type_a,
               QString descr_a,InvestigationType subtype_a,
               QDate date_a,QString disease_a,QWidget *parent=0);
    QSize sizeHint() const;
private:
    QStringList InvestigationTypeNames;
    ItemType type;
    QString *descr;
    QString *subtype;
    QDate *date;
    ItemWidget *w;
    QMenu *menu;
    Engine *engine;
    IndexItem *item;
    QString keyword,uroot;

    LinkDiseaseDialog *link_dialog;
    bool eventFilter(QObject *, QEvent *);

signals:
    void triggerOpen(QString,ItemButton::ItemType);
    void triggerEdit(IndexItem);
    void triggerDisease(IndexItem);
    void triggerDelete(IndexItem,ItemButton *);

public slots:
    void performAction(QAction *action);
    void displayItemDetails();

};

#endif // ITEMBUTTON_H
