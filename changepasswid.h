#ifndef CHANGEPASSWID_H
#define CHANGEPASSWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QErrorMessage>
#include <QString>

#include "passman/passman.h"

class ChangePassWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    QLabel *old_l,*new_l,*retype_l;
    QPushButton *ok_button;
    QLineEdit *old_e,*new_e,*retype_e;
    QString curr_user;
public:
    explicit ChangePassWid(QString currentuser,QWidget *parent = 0);
    
signals:
    
public slots:
    void passauth();
    
};

#endif // CHANGEPASSWID_H
