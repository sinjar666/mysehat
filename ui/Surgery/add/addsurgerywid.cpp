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

#include "addsurgerywid.h"

AddSurgeryWid::AddSurgeryWid(QString rootdir,QWidget *parent) :
    QWidget(parent)
{
    path=rootdir;
    QLabel *details_l=new QLabel(tr("Details"));
    QLabel *date_l=new QLabel(tr("Date"));
    edit=new QDateEdit();
    edit->setDate(QDate::currentDate());
    details_t=new QTextEdit();
    //QPushButton *link_button=new QPushButton(tr("Link appointment"));
    //QLabel *blank=new QLabel();
    QPushButton *save=new QPushButton(tr("SAVE"));
    QPushButton *reset=new QPushButton(tr("RESET"));
    QGridLayout *hlayout=new QGridLayout(this);
    hlayout->setVerticalSpacing(20);
    hlayout->addWidget(date_l,0,0);
    hlayout->addWidget(edit,0,1);
    hlayout->addWidget(details_l,1,0);
    hlayout->addWidget(details_t,1,1);
    hlayout->addWidget(save,2,0);
    hlayout->addWidget(reset,2,1);

    connect(reset,SIGNAL(clicked()),this,SLOT(reset_function()));
    connect(save,SIGNAL(clicked()),this,SLOT(perform_save()));
}

QDate AddSurgeryWid::getdate()
{
    return edit->date();
}

QString AddSurgeryWid::getdetails()
{
    return details_t->toPlainText();
}

void AddSurgeryWid::reset_function()
{
    edit->setDate(QDate::currentDate());
    details_t->clear();
}

void AddSurgeryWid::perform_save()
{
    if(details_t->toPlainText().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the details"));
    }
    else
    {
    model=new Surgery();
    IdGen *id_gen;
    id_gen = new IdGen(path);
    QString id=id_gen->generate(IdGen::SURGERY_T);

    model->setDate(getdate());
    model->setDetails(getdetails());

    XSurgery *xml=new XSurgery(model,id);
    xml->saveData();

    IndexItem *index_t=new IndexItem(getdate(),id,5,QString(""));

    Engine *eng=new Engine(path+"/");
    eng->loadIndex();

    QStringList keys;
    KeyFinder *keyfin=new KeyFinder(getdetails());
    keys=keyfin->generate();

    QString key;
    foreach(key,keys)   {
        eng->addEntry(key,*index_t);
    }
    eng->saveIndex();
    model->deleteLater();
    id_gen->deleteLater();
    xml->deleteLater();
    eng->deleteLater();
    keyfin->deleteLater();
    delete(index_t);
    close();
    }
}
