#ifndef BOTTOM_H
#define BOTTOM_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class bottom : public QWidget
{
    QPushButton *button1,*button2;
    QHBoxLayout *h;
    Q_OBJECT
public:
    explicit bottom(QWidget *parent = 0);

signals:
    void resetPressed();
    void savePressed();

public slots:
    void onReset();
    void onSave();

};

#endif // EDITBOTTOM_H
