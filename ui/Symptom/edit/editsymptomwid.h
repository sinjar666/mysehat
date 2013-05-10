#ifndef EDITSYMPTOMWID_H
#define EDITSYMPTOMWID_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QTextEdit>
#include <QLineEdit>
#include <QErrorMessage>

#include "model/symptom.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "xml/Symptom/xsymptom.h"
#include "KeyFinder/keyfinder.h"

class EditSymptomWid : public QWidget
{
    Q_OBJECT
    IndexItem old_item;
    QGridLayout *g_layout;
    QString path;
    Symptom *model;
    XSymptom *xml;
    QLineEdit *charac;
    QTextEdit *desc;
    QPushButton *save_b,*reset_b;
    QLabel *details_l,*charac_l;

public:
    explicit EditSymptomWid(QString path_a,IndexItem olditem,QWidget *parent = 0);

signals:

public slots:
    void perform_save();
    void perform_reset();

};

#endif // EDITSYMPTOMWID_H
