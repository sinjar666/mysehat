#ifndef APPOINTMENTLIST_H
#define APPOINTMENTLIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "appointmentbutton.h"

class AppointmentList : public QWidget
{
    Q_OBJECT
    QVBoxLayout *v_layout;
public:
    explicit AppointmentList(QList<AppointmentButton *> list_a,
                             QWidget *parent = 0);
    void addButtons(QList<AppointmentButton *> list);

signals:

public slots:

};

#endif // APPOINTMENTLIST_H
