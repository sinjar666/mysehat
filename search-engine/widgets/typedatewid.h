#ifndef TYPEDATEWID_H
#define TYPEDATEWID_H

#include <QWidget>
#include <QLabel>
#include <QDate>
#include <QHBoxLayout>

class TypeDateWid : public QWidget
{
    Q_OBJECT
    QLabel *type_l,*date_l;
    QHBoxLayout *layout;
public:
    explicit TypeDateWid(QString type,QDate date,QString disease,QWidget *parent = 0);

signals:

public slots:

};

#endif // TYPEDATEWID_H
