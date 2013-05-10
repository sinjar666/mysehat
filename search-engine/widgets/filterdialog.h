#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QCheckBox>
#include "../engine/engine.h"

class FilterDialog : public QDialog
{
    Q_OBJECT

    QGridLayout *layout;
    QCheckBox *symptom,*allergen,*drug,*investigation,*surgery,*familyhist;
    Engine *obj;

public:
    explicit FilterDialog(Engine *e,quint8 arg,QWidget *parent = 0);

signals:

public slots:
    void symptomChecked(int state);
    void allergenChecked(int state);
    void drugChecked(int state);
    void investigationChecked(int state);
    void surgeryChecked(int state);
    void familyhistChecked(int state);


};

#endif // FILTERDIALOG_H
