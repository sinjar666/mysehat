#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include <QPixmap>
#include "rwid.h"

class ItemWidget : public QWidget
{
    Q_OBJECT
    QLabel *icon;
    RWid *w;
    QHBoxLayout *layout;
public:
    explicit ItemWidget(const QPixmap img,QString descr,QString type,QDate date,QString disease,QWidget *parent = 0);
    QSize sizeHint() const;
signals:

public slots:

};

#endif // ITEMWIDGET_H
