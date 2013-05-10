#ifndef APPOINTMENTDATETIMEWID_H
#define APPOINTMENTDATETIMEWID_H

#include <QWidget>
#include <QDateTimeEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QDate>
#include <QTime>

class AppointmentDateTimeWid : public QWidget
{
    Q_OBJECT
    QDateTimeEdit *datetime_e;
    QLabel *datetime_l;
    QHBoxLayout *lay;

public:
    explicit AppointmentDateTimeWid(QWidget *parent = 0);
    void resetAll();
    QDate getDate();
    QTime getTime();
signals:
    
public slots:
    
};

#endif // APPOINTMENTDATETIMEWID_H
