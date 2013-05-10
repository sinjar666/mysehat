#ifndef DIALOGRIGHT_H
#define DIALOGRIGHT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class DialogRight : public QWidget
{
    Q_OBJECT
    QVBoxLayout *lay;
    QPushButton *new_b,*choose_b;
    QString name;

public:
    explicit DialogRight(QWidget *parent=0);
    
signals:
    void choosePressed();
    void newPressed();
    
public slots:
    void onChoose();
    void onNew();
    
};

#endif // DIALOGRIGHT_H
