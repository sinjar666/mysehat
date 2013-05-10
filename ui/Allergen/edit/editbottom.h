#ifndef EDITBOTTOM_H
#define EDITBOTTOM_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class EditBottom : public QWidget
{
    QPushButton *button1,*button2;
    QHBoxLayout *h;
    Q_OBJECT
public:
    explicit EditBottom(QWidget *parent = 0);

signals:
    void resetPressed();
    void savePressed();

public slots:
    void onReset();
    void onSave();

};

#endif // BOTTOM_H
