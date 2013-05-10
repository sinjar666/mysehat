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

#include "itembutton.h"

ItemButton::ItemButton(QString uroot_a,Engine *arg, IndexItem *i,QString key_a,ItemButton::ItemType type_a, QString descr_a,
                       InvestigationType subtype_a, QDate date_a, QString disease_a,
                       QWidget *parent)
    :QPushButton(parent)
{
    uroot=uroot_a;
    engine=arg;
    item = i;
    keyword=key_a;
    InvestigationTypeNames << "Angiography" <<
                                            "Biopsy" << "Blood Test" <<
                                            "Colonoscopy" <<
                                            "CT" <<
                                            "ECG" <<
                                            "Echo Cardiography" <<
                                            "Electro Encephalography (EEG)" <<
                                            "Endoscopy" <<
                                            "FNAC" <<
                                            "Funduscopy" <<
                                            "Holter Test" <<
                                            "MRI" <<
                                            "Sputum Test" <<
                                            "Stool Test" <<
                                            "Throat Swab" <<
                                            "Treadmill" <<
                                            "Urine Test" <<
                                            "Ultrasonography (USG)" <<
                                            "X-Ray" <<
                                            "Other";

    QImage temp;
    switch(type_a)  {
    case Symptom:
        temp = QImage(":/icons/symptom.xpm");
        break;
    case Allergen:
        temp = QImage(":/icons/allergen.xpm");
        break;
    case Drug:
        temp = QImage(":/icons/drug.xpm");
        break;
    case Investigation:
        temp = QImage(":/icons/investigation.xpm");
        break;
    case Surgery:
        temp = QImage(":/icons/surgery.xpm");
        break;
    case FamilyHistory:
        temp = QImage(":/icons/family.xpm");
        break;
    case Vaccine:
        temp=QImage(":/icons/vaccine.xpm");
        break;
    case Appointment:
        temp=QImage(":/icons/appointment.jpg");
        break;
    default:
        break;
    }
    type=type_a;
    descr= new QString(descr_a);
    date=new QDate(date_a);
    if(subtype_a == Other)  {
        subtype = new QString();
    }
    else  {
        subtype = new QString(InvestigationTypeNames.at((int)subtype_a));
    }
    //qDebug() << subtype;

    menu = new QMenu(this);
    menu->addAction(new QAction("Edit",this));
    menu->addAction(new QAction("Delete",this));
    if(disease_a == "")
        menu->addAction(new QAction("Link disease...",this));
    w = new ItemWidget(QPixmap::fromImage(temp),*descr,*subtype,*date,disease_a,this);
    installEventFilter(this);
    connect(menu,SIGNAL(triggered(QAction*)),this,SLOT(performAction(QAction*)));
    connect(this,SIGNAL(clicked()),this,SLOT(displayItemDetails()));
}

QSize ItemButton::sizeHint() const  {
    return(QSize(780,100));
}

bool ItemButton::eventFilter(QObject *obj, QEvent *event)   {
    if(event->type() == QEvent::ContextMenu)    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *> (event);

        menu->exec(mouseEvent->globalPos());

         return false;
    }
    else return QPushButton::eventFilter(obj,event);
}

void ItemButton::performAction(QAction *action) {
    if(action->text() == "Delete")    {
        emit triggerDelete(*item,this);

        //this->hide();
    }
    if(action->text() == "Edit")  {
        //Perform edit
        emit triggerEdit(*item);
    }
    if(action->text() == "Link disease...")  {
        emit triggerDisease(*item);
    }
}

void ItemButton::displayItemDetails()   {
    emit triggerOpen(item->getLocation(),type);
}
