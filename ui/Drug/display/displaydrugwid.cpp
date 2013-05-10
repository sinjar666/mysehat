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

#include "displaydrugwid.h"

DisplayDrugWid::DisplayDrugWid(Drug *arg, QWidget *parent) :
    QWidget(parent)
{
    model=arg;
    name_l = new QLabel(tr("Name of drug"));
    name_e = new QLabel(model->getName());
    date_l = new QLabel(tr("Date"));
    date_e = new QLabel(model->getDate().toString());
    duration_l = new QLabel(tr("Duration"));
    duration_e = new QLabel(QString::number(model->getDuration()));
    app_b = new QPushButton(tr("Appointments..."));
    lay = new QGridLayout(this);
    lay->addWidget(name_l,0,0);
    lay->addWidget(name_e,0,1);
    lay->addWidget(date_l,1,0);
    lay->addWidget(date_e,1,1);
    lay->addWidget(duration_l,2,0);
    lay->addWidget(duration_e,2,1);
    lay->addWidget(app_b,3,0);
    lay->addWidget(new QLabel(),3,1);
    connect(app_b,SIGNAL(clicked()),this,SLOT(displayLinks()));
}

void DisplayDrugWid::displayLinks() {
    ShowItemsDialog *dialog = new ShowItemsDialog(Engine::APPOINTMENT_F,model->getLinkedTo(),&to_open,this);
    connect(dialog,SIGNAL(accepted()),this,SLOT(displayAppointment()));
    dialog->show();
}

void DisplayDrugWid::displayAppointment()
{
    DisplayAppointmentWid *widget;
    Appointment *model = new Appointment(this);
    XAppointment *xml = new XAppointment(model,to_open);
    xml->readData();
    xml->deleteLater();
    widget = new DisplayAppointmentWid(false,model,this);
    widget->setAttribute(Qt::WA_Maemo5StackedWindow);
    widget->setAttribute(Qt::WA_DeleteOnClose);
    widget->setWindowFlags(widget->windowFlags() | Qt::Window);
    widget->show();
}
