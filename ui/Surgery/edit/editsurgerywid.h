#ifndef EDITSURGERYWID_H
#define EDITSURGERYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QErrorMessage>

#include "model/surgery.h"
#include "KeyFinder/keyfinder.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "xml/Surgery/xsurgery.h"

class EditSurgeryWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    QDateEdit *date_e;
    QString path;
    IndexItem old_item;
    Surgery *model;
    XSurgery *xml;
    QLabel *date_l,*detail_l;
    QTextEdit *detail_e;
    QPushButton *save_b,*reset_b;
public:
    explicit EditSurgeryWid(QString path_a,IndexItem olditem,QWidget *parent = 0);

signals:

public slots:
    void perform_save();
    void perform_reset();
};

#endif // EDITSURGERYWID_H
