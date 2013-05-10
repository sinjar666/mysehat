#ifndef ADDSURGERYWID_H
#define ADDSURGERYWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QString>
#include <QDate>
#include <QErrorMessage>

#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "model/surgery.h"
#include "xml/Surgery/xsurgery.h"

class AddSurgeryWid : public QWidget
{
    Q_OBJECT
    QDateEdit *edit;
    QTextEdit *details_t;
    Surgery *model;
    QString path;
public:
    explicit AddSurgeryWid(QString rootdir,QWidget *parent = 0);
    QDate getdate();
    QString getdetails();


signals:

public slots:
    void reset_function();
    void perform_save();
};

#endif // ADDSURGERYWID_H
