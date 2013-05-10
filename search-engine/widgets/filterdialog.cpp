/****************************************************************************************
 * Copyright (c) 2012 Srijan Mukherjee <srijanmukherjee06@yahoo.com>                    *
 * Copyright (c) 2012 Tumul Richesh <tumullko@gmail.com>                                *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 3 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#include "filterdialog.h"

FilterDialog::FilterDialog(Engine *e,quint8 arg,QWidget *parent) :
    QDialog(parent)
{
    obj=e;
    symptom = new QCheckBox("Symptom");
    allergen = new QCheckBox("Allergen");
    drug = new QCheckBox("Drug");
    investigation = new QCheckBox("Investigation");
    surgery = new QCheckBox("Surgery");
    familyhist = new QCheckBox("Family History");

    if((arg & Engine::SYMPTOM_F) >0)
        symptom->setChecked(true);
    if((arg & Engine::ALLERGEN_F)>0)
        allergen->setChecked(true);
    if((arg & Engine::DRUG_F)>0)
        drug->setChecked(true);
    if((arg & Engine::INVESTIGATION_F)>0)
        investigation->setChecked(true);
    if((arg & Engine::SURGERY_F)>0)
        surgery->setChecked(true);
    if((arg & Engine::FAMILYHIST_F)>0)
        familyhist->setChecked(true);

    layout=new QGridLayout(this);
    layout->addWidget(symptom,0,0);
    layout->addWidget(allergen,0,1);
    layout->addWidget(drug,0,2);
    layout->addWidget(investigation,1,0);
    layout->addWidget(surgery,1,1);
    layout->addWidget(familyhist,1,2);

    connect(symptom,SIGNAL(stateChanged(int)),this,SLOT(symptomChecked(int)));
    connect(allergen,SIGNAL(stateChanged(int)),this,SLOT(allergenChecked(int)));
    connect(drug,SIGNAL(stateChanged(int)),this,SLOT(drugChecked(int)));
    connect(investigation,SIGNAL(stateChanged(int)),this,SLOT(investigationChecked(int)));
    connect(surgery,SIGNAL(stateChanged(int)),this,SLOT(surgeryChecked(int)));
    connect(familyhist,SIGNAL(stateChanged(int)),this,SLOT(familyhistChecked(int)));

}

void FilterDialog::symptomChecked(int state)    {
    obj->setFilter(Engine::SYMPTOM_F,(state==Qt::Checked)?true:false);
}

void FilterDialog::allergenChecked(int state)    {
    obj->setFilter(Engine::ALLERGEN_F,(state==Qt::Checked?true:false));
}

void FilterDialog::drugChecked(int state)    {
    obj->setFilter(Engine::DRUG_F,(state==Qt::Checked?true:false));
}

void FilterDialog::investigationChecked(int state)    {
    obj->setFilter(Engine::INVESTIGATION_F,(state==Qt::Checked?true:false));
}

void FilterDialog::surgeryChecked(int state)    {
    obj->setFilter(Engine::SURGERY_F,(state==Qt::Checked?true:false));
}

void FilterDialog::familyhistChecked(int state)    {
    obj->setFilter(Engine::FAMILYHIST_F,(state==Qt::Checked?true:false));
}
