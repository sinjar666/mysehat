#ifndef VACCINEBOTTOMWID_H
#define VACCINEBOTTOMWID_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class VaccineBottomWid : public QWidget
{
    Q_OBJECT
    QPushButton *save_b,*reset_b;
    QHBoxLayout *lay;
public:
    explicit VaccineBottomWid(QWidget *parent = 0);
    
signals:
    void sendReset();
    void sendSave();
    
public slots:
    void onResetPressed();
    void onSavePressed();
};

#endif // VACCINEBOTTOMWID_H
