#ifndef EDITALLERGENWID_H
#define EDITALLERGENWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QErrorMessage>

#include "editbottom.h"
#include "editmiddle.h"
#include "editupper.h"
#include "IdGen/idgen.h" //generates Id
#include "KeyFinder/keyfinder.h" //generates keywords
#include "model/allergen.h"
#include "xml/Allergen/xallergen.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"

class EditAllergenWid : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout;
    EditUpper *u;
    EditMiddle *m;
    EditBottom *b;

    Allergen *model;

    QString path,old;
    IndexItem old_item;
public:
    explicit EditAllergenWid(QString rootdir,IndexItem olditem_a,QWidget *parent);

    
signals:
    
public slots:
    void performReset(); //to clear all the fields
    void performSave(); //to save the file
};

#endif // ADDALLERGENWID_H
