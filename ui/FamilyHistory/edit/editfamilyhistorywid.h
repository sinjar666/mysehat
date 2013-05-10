#ifndef EDITFAMILYHISTORYWID_H
#define EDITFAMILYHISTORYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QDateEdit>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>

#include "model/familyhistory.h"
#include "xml/FamilyHistory/xfamilyhistory.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "KeyFinder/keyfinder.h"

class EditFamilyHistoryWid : public QWidget
{
    Q_OBJECT
    QGridLayout *lay;
    QLabel *name_l;
    QLineEdit *name_e;
    QCheckBox *mother_e,*father_e,*brother_e,*sister_e,*grandfather_e,*grandmother_e;
    QPushButton *save_b,*reset_b;

    IndexItem old_item;
    FamilyHistory *model;
    XFamilyHistory *xml;
    QString path;

public:
    explicit EditFamilyHistoryWid(QString path_a,IndexItem olditem,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // EDITFAMILYHISTORYWID_H
