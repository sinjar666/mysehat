#include "itemlist.h"

ItemList::ItemList(QString uroot_a,Engine *arg, QWidget *parent) :
    QWidget(parent)
{
    uroot=uroot_a;
    engine=arg;
    lay = new QVBoxLayout(this);
    setLayout(lay);
    //performSearch(QString());
}
ItemList::ItemList(QString uroot_a,Engine *arg, QList<ItemButton *> l, QWidget *parent):
    QWidget(parent)
{
    uroot=uroot_a;
    engine=arg;
    lay=new QVBoxLayout(this);
    addButtons(l);
}


void ItemList::addButtons(QList<ItemButton *> l)    {
    ItemButton *i;
    foreach(i,l)    {
        lay->addWidget(i);
        connect(i,SIGNAL(triggerOpen(QString,ItemButton::ItemType)),this,SLOT(sendTrigger(QString,ItemButton::ItemType)));
        connect(i,SIGNAL(triggerEdit(IndexItem)),this,SLOT(sendTrigger2(IndexItem)));
        connect(i,SIGNAL(triggerDisease(IndexItem)),this,SLOT(sendTrigger3(IndexItem)));
        connect(i,SIGNAL(triggerDelete(IndexItem,ItemButton *)),this,SLOT(sendTrigger4(IndexItem,ItemButton *)));
    }
}

void ItemList::sendTrigger(QString loc, ItemButton::ItemType type)  {
    emit triggerOpen(loc,type);
}

void ItemList::sendTrigger2(IndexItem item) {
    emit triggerEdit(item);
}

void ItemList::sendTrigger3(IndexItem item) {
    emit triggerDisease(item);
}

void ItemList::sendTrigger4(IndexItem item, ItemButton *obj) {
    emit triggerDelete(item,obj);
}
