#ifndef RWID_H
#define RWID_H

#include <QWidget>
#include <QVBoxLayout>
#include "typedatewid.h"

class RWid : public QWidget
{
    Q_OBJECT
    TypeDateWid *w;
    QLabel *descr_e;
    QVBoxLayout *layout;
public:
    explicit RWid(QString descr,QString type,QDate date,QString disease,QWidget *parent = 0);
    QSize sizeHint() const;
signals:

public slots:

};

#endif // RWID_H
