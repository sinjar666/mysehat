#include "additemwidget.h"

AddItemWidget::AddItemWidget(QDir *pathdir_a,QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("mysehat(add details)");
    pathdir=pathdir_a;
    title_l = new QLabel(tr("Choose an item to add"));
    app_b = new AddItemButton(AddItemButton::APPOINTMENT_T);
    sym_b = new AddItemButton(AddItemButton::SYMPTOM_T);
    inv_b = new AddItemButton(AddItemButton::INVESTIGATION_T);
    sur_b = new AddItemButton(AddItemButton::SURGERY_T);
    drug_b = new AddItemButton(AddItemButton::DRUG_T);
    all_b = new AddItemButton(AddItemButton::ALLERGEN_T);
    vac_b = new AddItemButton(AddItemButton::VACCINE_T);
    fam_b = new AddItemButton(AddItemButton::FAMILYHISTORY_T);
    lay = new QGridLayout(this);
    lay->addWidget(title_l,0,0,1,-1);
    lay->addWidget(app_b,1,0);
    lay->addWidget(sym_b,1,1);
    lay->addWidget(inv_b,1,2);
    lay->addWidget(sur_b,1,3);
    lay->addWidget(drug_b,2,0);
    lay->addWidget(all_b,2,1);
    lay->addWidget(vac_b,2,2);
    lay->addWidget(fam_b,2,3);

    connect(all_b,SIGNAL(clicked()),this,SLOT(AddAllergenClicked()));
    connect(vac_b,SIGNAL(clicked()),this,SLOT(AddVaccineClicked()));
    connect(inv_b,SIGNAL(clicked()),this,SLOT(AddInvestigationClicked()));
    connect(app_b,SIGNAL(clicked()),this,SLOT(AddAppointmentClicked()));
    connect(sur_b,SIGNAL(clicked()),this,SLOT(AddSurgeryClicked()));
    connect(fam_b,SIGNAL(clicked()),this,SLOT(AddFamilyHistoryClicked()));
    connect(sym_b,SIGNAL(clicked()),this,SLOT(AddSymptomClicked()));
    connect(drug_b,SIGNAL(clicked()),this,SLOT(AddDrugClicked()));

    add_allergen=new AddAllergenWid(pathdir->absolutePath(),this);
    add_allergen->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_allergen->setAttribute(Qt::WA_DeleteOnClose);
    add_allergen->setWindowFlags(add_allergen->windowFlags()|Qt::Window);

    add_vaccine=new AddVaccineWid(pathdir->absolutePath(),this);
    add_vaccine->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_vaccine->setAttribute(Qt::WA_DeleteOnClose);
    add_vaccine->setWindowFlags(add_vaccine->windowFlags()|Qt::Window);

    add_invest=new AddInvestigationWid(pathdir->absolutePath(),this);
    add_invest->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_invest->setAttribute(Qt::WA_DeleteOnClose);
    add_invest->setWindowFlags(add_invest->windowFlags()|Qt::Window);



    add_drug=new AddDrugWid(pathdir->absolutePath(),this);
    add_drug->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_drug->setAttribute(Qt::WA_DeleteOnClose);
    add_drug->setWindowFlags(add_invest->windowFlags()|Qt::Window);

    add_family=new AddFamilyHistoryWid(pathdir->absolutePath(),this);
    add_family->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_family->setAttribute(Qt::WA_DeleteOnClose);
    add_family->setWindowFlags(add_invest->windowFlags()|Qt::Window);

    add_surgery=new AddSurgeryWid(pathdir->absolutePath(),this);
    add_surgery->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_surgery->setAttribute(Qt::WA_DeleteOnClose);
    add_surgery->setWindowFlags(add_invest->windowFlags()|Qt::Window);

    add_symptom=new AddSymptomWid(pathdir->absolutePath(),this);
    add_symptom->setAttribute(Qt::WA_Maemo5StackedWindow);
    //add_symptom->setAttribute(Qt::WA_DeleteOnClose);
    add_symptom->setWindowFlags(add_invest->windowFlags()|Qt::Window);
}

void AddItemWidget::AddAllergenClicked()
{

    add_allergen->show();
    //add_allergen->deleteLater();
}

void AddItemWidget::AddVaccineClicked()
{

    add_vaccine->show();
    //add_vaccine->deleteLater();
}

void AddItemWidget::AddInvestigationClicked()
{

    add_invest->show();
    //add_invest->deleteLater();
}

void AddItemWidget::AddAppointmentClicked()
{
    add_appoint=new AddAppointmentWid(pathdir->absolutePath(),this);
    add_appoint->setAttribute(Qt::WA_Maemo5StackedWindow);
    add_appoint->setAttribute(Qt::WA_DeleteOnClose);
    add_appoint->setWindowFlags(add_invest->windowFlags()|Qt::Window);
    add_appoint->show();
    //add_appoint->deleteLater();
}

void AddItemWidget::AddDrugClicked()
{

    add_drug->show();
    //add_drug->deleteLater();
}

void AddItemWidget::AddFamilyHistoryClicked()
{

    add_family->show();
    //add_family->deleteLater();
}

void AddItemWidget::AddSurgeryClicked()
{

    add_surgery->show();
    //add_surgery->deleteLater();
}

void AddItemWidget::AddSymptomClicked()
{

    add_symptom->show();
    //add_symptom->deleteLater();
}
