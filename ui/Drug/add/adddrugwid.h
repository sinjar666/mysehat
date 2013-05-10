#ifndef ADDDRUGWID_H
#define ADDDRUGWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QErrorMessage>

#include "model/drug.h"
#include "xml/Drug/xdrug.h"
#include "config/config.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"

class AddDrugWid : public QWidget
{
    Q_OBJECT
    QString path;
    QLabel *name_l,*date_l,*duration_l;
    QDateEdit *date_e;
    QLineEdit *name_e;
    QGridLayout *lay;
    QSpinBox *duration_e;
    QPushButton *save_b,*reset_b;


public:
    explicit AddDrugWid(QString rootdir,QWidget *parent = 0);
    
signals:
    
public slots:
    void performSave();
    void performReset();
    
};

#endif // ADDDRUGWID_H
