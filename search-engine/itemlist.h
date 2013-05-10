#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QWidget>
#include <QGroupBox>
#include "engine/indexitem.h"
#include "engine/engine.h"
#include "itembutton.h"

class ItemList : public QWidget
{
    Q_OBJECT
    QVBoxLayout *lay;
    QGroupBox *box;
    Engine *engine;
    QString uroot;
    //ItemButton *temp;
public:
    explicit ItemList(QString uroot_a,Engine *arg,QWidget *parent = 0);
    ItemList(QString uroot_a,Engine *arg,QList<ItemButton *>l,QWidget *parent=0);
    void addButtons(QList<ItemButton *> l);
    //QSize sizeHint();

signals:
    void triggerOpen(QString, ItemButton::ItemType);
    void triggerEdit(IndexItem);
    void triggerDisease(IndexItem);
    void triggerDelete(IndexItem,ItemButton *);

public slots:
    void sendTrigger(QString loc,ItemButton::ItemType type);
    void sendTrigger2(IndexItem item);
    void sendTrigger3(IndexItem item);
    void sendTrigger4(IndexItem item,ItemButton *);

};


#endif // ITEMLIST_H
