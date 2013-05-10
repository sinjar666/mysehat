#ifndef APPOINTMENTNAMEWID_H
#define APPOINTMENTNAMEWID_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

class AppointmentNameWid : public QWidget
{
    Q_OBJECT
    QLabel *name_l;
    QLineEdit *name_e;
    QHBoxLayout *lay;
public:
    explicit AppointmentNameWid(QWidget *parent = 0);
    void resetAll();
    QString getName();
    
signals:
    
public slots:
    
};

#endif // APPOINTMENTNAMEWID_H
