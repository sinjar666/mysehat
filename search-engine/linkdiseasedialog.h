#ifndef LINKDISEASEDIALOG_H
#define LINKDISEASEDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include "dialogright.h"
#include "xdisease/xdisease.h"
#include "addnewdisease.h"

class LinkDiseaseDialog : public QDialog
{
    Q_OBJECT
    QListWidget *disease_list;
    QHBoxLayout *lay;
    DialogRight *right_w;
    QString *disease,loc,uroot;
    AddNewDisease *new_dialog;
    QString name;
public:
    explicit LinkDiseaseDialog(QString uroot_a,QString *arg,QString loc_a,QWidget *parent = 0);
    void populate();
    
signals:
    
public slots:
    void addNew();
    void itemChosen();
    
};

#endif // LINKDISEASEDIALOG_H
