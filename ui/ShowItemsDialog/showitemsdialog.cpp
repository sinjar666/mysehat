#include "showitemsdialog.h"

ShowItemsDialog::ShowItemsDialog(Engine::Filters arg,QList<QString> items_arg, QString *val_a, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    setWindowTitle(tr("Choose an item"));
    val=val_a;
    type=arg;
    view = new QListWidget();
    items = items_arg;
    //qDebug() << items;
    QString item;
    foreach(item,items) {
        QString Str;
        switch(type)    {
        case Engine::SYMPTOM_F:
        {
            Symptom *symptom = new Symptom();
            XSymptom *xsymptom = new XSymptom(symptom,item);
            xsymptom->readData();
            Str += symptom->getDescription();
            Str.truncate(20);
            Str += "...";
            xsymptom->deleteLater();
            symptom->deleteLater();
            break;
        }
        case Engine::DRUG_F:
        {
            Drug *drug = new Drug();
            XDrug *xdrug = new XDrug(drug,item);
            xdrug->readData();
            Str += drug->getName();
            Str.truncate(20);
            Str += "...";
            xdrug->deleteLater();
            drug->deleteLater();
            break;
        }
        case Engine::SURGERY_F:
        {
            Surgery *surgery = new Surgery();
            XSurgery *xsurgery = new XSurgery(surgery,item);
            xsurgery->readData();
            Str += surgery->getDetails();
            Str.truncate(20);
            Str += "...";
            xsurgery->deleteLater();
            surgery->deleteLater();
            break;
        }
        case Engine::INVESTIGATION_F:
        {
            Investigation *inv = new Investigation();
            XInvestigation *xinv = new XInvestigation(inv,item);
            xinv->readData();
            Str += inv->getDetails();
            Str.truncate(20);
            Str += "...";
            xinv->deleteLater();
            inv->deleteLater();
            break;
        }
        case Engine::APPOINTMENT_F:
        {
            Appointment *app = new Appointment();
            XAppointment *xapp = new XAppointment(app,item);
            xapp->readData();
            Str += app->getName();
            xapp->deleteLater();
            app->deleteLater();
            break;
        }
        default:
            qDebug("Do nothing");
        }
        view->addItem(Str);
    }
    lay = new QVBoxLayout(this);
    if(items.length()>0)    {
    lay->addWidget(view);
    connect(view,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onItemDoubleClicked(QListWidgetItem*)));
    }
    else    {
        lay->addWidget(new QLabel("<font size=\"3\">No items to show.</font>"));
    }
}

void ShowItemsDialog::onItemDoubleClicked(QListWidgetItem *item)    {
    int row=view->currentRow();
    *val=items[row];
    accept();
}
