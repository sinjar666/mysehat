#ifndef ADDSYMPTOMWID_H
#define ADDSYMPTOMWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QDate>
#include <QErrorMessage>

#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "xml/Symptom/xsymptom.h"
#include "model/symptom.h"

class AddSymptomWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    QLabel *desc,*char_l;
    QTextEdit *details;
    QLineEdit *charac;
    QString path;
    QPushButton *save,*reset;
    Symptom *model;

public:
    explicit AddSymptomWid(QString rootdir,QWidget *parent = 0);

signals:

public slots:
    void perform_save();
    void reset_function();
};

#endif // ADDSYMPTOMWID_H
