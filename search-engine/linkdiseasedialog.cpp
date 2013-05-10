#include "linkdiseasedialog.h"

LinkDiseaseDialog::LinkDiseaseDialog(QString uroot_a, QString *arg, QString loc_a, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    uroot=uroot_a;
    loc=loc_a;
    disease=arg;
    setModal(false);
    setAttribute(Qt::WA_DeleteOnClose);
    lay = new QHBoxLayout(this);
    disease_list = new QListWidget();
    right_w = new DialogRight();
    populate();
    lay->addWidget(disease_list);
    lay->addWidget(right_w);
    new_dialog = new AddNewDisease(&name,this);
    connect(right_w,SIGNAL(newPressed()),this,SLOT(addNew()));
    connect(right_w,SIGNAL(choosePressed()),this,SLOT(itemChosen()));
}

void LinkDiseaseDialog::populate()  {
    //Read file and populate the list
    XDisease *obj;
    obj = new XDisease(uroot);
    QStringList diseases = obj->getdname();
    disease_list->clear();
    disease_list->addItems(diseases);
    obj->deleteLater();
}

void LinkDiseaseDialog::addNew()    {
    if(new_dialog->exec())  {
        disease_list->insertItem(0,name);
        disease_list->setCurrentRow(0);
    }
}

void LinkDiseaseDialog::itemChosen()    {
    *disease=disease_list->currentItem()->text();
    XDisease *obj = new XDisease(uroot);
    obj->adddisease(*disease,loc);
    obj->deleteLater();
   // qDebug()<<*disease;
    accept();
}
