#ifndef ADDFAMILYHISTORYWID_H
#define ADDFAMILYHISTORYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QErrorMessage>

#include "model/familyhistory.h"
#include "xml/FamilyHistory/xfamilyhistory.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "config/config.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"

class AddFamilyHistoryWid : public QWidget
{
    Q_OBJECT
    QString path;
    QGridLayout *lay;
    QLabel *name_l;
    QLineEdit *name_e;
    QCheckBox *mother_e,*father_e,*brother_e,*sister_e,*grandfather_e,*grandmother_e;
    QPushButton *save_b,*reset_b;
public:
    explicit AddFamilyHistoryWid(QString rootdir,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // ADDFAMILYHISTORYWID_H
