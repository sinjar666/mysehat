#ifndef UPPER_H
#define UPPER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

class upper : public QWidget
{
    Q_OBJECT
    QLabel *l;
    QLineEdit *line;
    QHBoxLayout *h;
public:
    explicit upper(QWidget *parent = 0);
    QString getName();
    void resetAll(); //u need to have such a function at all places where text fields can be reset

signals:

public slots:

};

#endif // UPPER_H
