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

#include "appointmentbutton.h"

AppointmentButton::AppointmentButton(QString path_a,QWidget *parent) :
    QPushButton(parent)
{
    path=path_a;
    h_layout=new QHBoxLayout(this);
    model=new Appointment();
    xappoint=new XAppointment(model,path);
    xappoint->readData();

    date_value=model->getDate();
    doc_name=model->getName();
    if(doc_name.length() >20)  {
        doc_name.truncate(20);
        doc_name.append(tr("..."));
    }
    //date_l = new QLabel("<font size=\"5\">"+date_value.toString()+"</font>");
    date_l = new QLabel(date_value.toString());
    date_l->setAlignment(Qt::AlignRight);
    //docname_l=new QLabel("<font size=\"5\">"+doc_name+"</font>");
    docname_l = new QLabel(doc_name);
    docname_l->setAlignment(Qt::AlignLeft);
    docname_l->setFont(QFont(tr("Nokia"),28));
    date_l->setFont(QFont(tr("Nokia"),28));
    //h_layout->setMargin(0);

    h_layout->addWidget(docname_l);
    h_layout->addWidget(date_l);

    connect(this,SIGNAL(clicked()),this,SLOT(appointClicked()));
}

QSize AppointmentButton::sizeHint() const
{
    return(QSize(740,70));
}

void AppointmentButton::appointClicked()
{
    emit AppointItemClicked(path);
}
