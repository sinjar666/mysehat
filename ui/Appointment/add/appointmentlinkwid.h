#ifndef APPOINTMENTLINKWID_H
#define APPOINTMENTLINKWID_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>

class AppointmentLinkWid : public QWidget
{
    Q_OBJECT
    QComboBox *chooser;
    QPushButton *link_b;
    QHBoxLayout *lay;

public:
    explicit AppointmentLinkWid(QWidget *parent = 0);
    
signals:
    void addLinks(int index);
    
public slots:
    void onButtonClicked();
};

#endif // APPOINTMENTLINKWID_H
