#ifndef EDITUPPER_H
#define EDITUPPER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

class EditUpper : public QWidget
{
    Q_OBJECT
    QLabel *l;
    QLineEdit *line;
    QHBoxLayout *h;
public:
    explicit EditUpper(QString name_a,QWidget *parent = 0);
    QString getName();
    void resetAll(); //u need to have such a function at all places where text fields can be reset

signals:

public slots:

};

#endif // UPPER_H
