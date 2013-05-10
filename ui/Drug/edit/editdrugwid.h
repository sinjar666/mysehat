#ifndef EDITDRUGWID_H
#define EDITDRUGWID_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QDateEdit>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>

#include "model/drug.h"
#include "xml/Drug/xdrug.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "KeyFinder/keyfinder.h"

class EditDrugWid : public QWidget
{
    Q_OBJECT
    QLabel *name_l,*date_l,*duration_l;
    QLineEdit *name_e;
    QDateEdit *date_e;
    QSpinBox *duration_e;
    QGridLayout *lay;
    QPushButton *save_b,*reset_b;
    QString path;
    IndexItem old_item;
    Drug *model;
    XDrug *xml;

public:
    explicit EditDrugWid(QString path_a,IndexItem olditem,QWidget *parent = 0);
    
signals:
    
public slots:
    void performReset();
    void performSave();
    
};

#endif // EDITDRUGWID_H
