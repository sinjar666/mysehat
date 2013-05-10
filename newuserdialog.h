#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QDebug>
#include <QErrorMessage>

#include "config/config.h"
#include "search-engine/engine/engine.h"
#include "passman/passman.h"

class NewUserDialog : public QDialog
{
    Q_OBJECT
    QLabel *newuser_l,*pass_l;
    QLineEdit *newuser_e,*pass_e;
    QPushButton *button;
    QGridLayout *glayout;
    QDir *pathdir;

public:
    explicit NewUserDialog(QDir *pathdir_a,QWidget *parent = 0);

signals:
    void username(QString username);

public slots:
    void config_user();

};

#endif // NEWUSERDIALOG_H
