#ifndef PASSDIALOGINFO_H
#define PASSDIALOGINFO_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class PassDialogInfo : public QDialog
{
    Q_OBJECT
    QLabel *t_message,*f_message;
    QPushButton *ok_button;
    QHBoxLayout *h_layout;
public:
    explicit PassDialogInfo(bool status,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PASSDIALOGINFO_H
