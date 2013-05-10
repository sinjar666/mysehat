#ifndef EDITMIDDLE_H
#define EDITMIDDLE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QString>
#include "model/allergen.h"


class EditMiddle : public QWidget
{
    Q_OBJECT
    QComboBox *box;
    QStringList *types;
    QLabel *label1;
    QHBoxLayout *h;
public:
    explicit EditMiddle(QWidget *parent = 0);
    Allergen::A_type getType(); //used to obtain the type
    //note the return type of the above function is exactly same
    //as the argument to be given to the setType function in the model
    //hence the model header has been included so that we can access this type
    void setType(Allergen::A_type type);
signals:

public slots:

};

#endif // MIDDLE_H
