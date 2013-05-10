#ifndef ADDALLERGENWID_H
#define ADDALLERGENWID_H

#include <QWidget>
#include <QVBoxLayout>
#include <QErrorMessage>

#include "bottom.h"
#include "middle.h"
#include "upper.h"
#include "IdGen/idgen.h"
#include "KeyFinder/keyfinder.h"
#include "model/allergen.h"
#include "xml/Allergen/xallergen.h"
#include "search-engine/engine/engine.h"

class AddAllergenWid : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout;
    upper *u;
    Middle *m;
    bottom *b;

    QString path;
public:
    explicit AddAllergenWid(QString rootdir,QWidget *parent = 0);

    
signals:
    
public slots:
    void performReset(); //to clear all the fields
    void performSave(); //to save the file
};

#endif // ADDALLERGENWID_H
