#ifndef PASSDIALOG_H
#define PASSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

#include "passman/passman.h"

class PassDialog : public QDialog
{
    Q_OBJECT
    QLineEdit *pass_e;
    QHBoxLayout *h_layout;
    QPushButton *done_button;
    QLabel *pass_l;
    QString curr_user;

public:
    explicit PassDialog(QString user_a,QWidget *parent = 0);
    
signals:
    void passtriggered(QString);
    
public slots:
    void button_clicked();
    
};

#endif // PASSDIALOG_H
