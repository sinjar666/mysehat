#ifndef ADDNEWDISEASE_H
#define ADDNEWDISEASE_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class AddNewDisease : public QDialog
{
    Q_OBJECT
    QLabel *name_l;
    QLineEdit *name_e;
    QPushButton *add_b;
    QHBoxLayout *lay;
    QString *name;
public:
    explicit AddNewDisease(QString *name_a,QWidget *parent);
    
signals:
    
public slots:
    void performAdd();
    
};

#endif // ADDNEWDISEASE_H
