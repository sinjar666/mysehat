#ifndef APPOINTMENTBOTTOMBAR_H
#define APPOINTMENTBOTTOMBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class AppointmentBottomBar : public QWidget
{
    Q_OBJECT
    QPushButton *add_b,*reset_b;
    QHBoxLayout *lay;
public:
    explicit AppointmentBottomBar(QWidget *parent = 0);
    
signals:
    void sendReset();
    void sendAdd();
    
public slots:
    void onResetPressed();
    void onAddPressed();

};

#endif // APPOINTMENTBOTTOMBAR_H
