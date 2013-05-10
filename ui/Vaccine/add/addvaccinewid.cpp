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

#include "addvaccinewid.h"

AddVaccineWid::AddVaccineWid(QString rootdir,QWidget *parent) :
    QWidget(parent)
{
    path = rootdir;
    lay = new QVBoxLayout(this);
    det_w = new VaccineDetailsWid();
    bottom = new VaccineBottomWid();
    lay->addWidget(det_w);
    lay->addWidget(bottom);
    connect(bottom,SIGNAL(sendSave()),this,SLOT(performSave()));
    connect(bottom,SIGNAL(sendReset()),this,SLOT(performReset()));
}

void AddVaccineWid::performReset()  {
    det_w->resetAll();
}

void AddVaccineWid::performSave()   {
    if(det_w->getName().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the vaccine"));
    }
    else
    {
    Vaccine *model = new Vaccine();
    //qDebug()<<"This is the path "+path;
    IdGen *id_gen = new IdGen(path);
    QString id = id_gen->generate(IdGen::VACCINE_T);
    model->setName(det_w->getName());
    model->setDate(det_w->getDate());
    model->setValidity(det_w->getValidity());
    XVaccine *xml = new XVaccine(model,id);
    xml->saveData();
    IndexItem index_item(det_w->getDate(),id,7,QString(""));
    Engine *engine = new Engine(path + "/");
    engine->loadIndex();
    QStringList keys;
    KeyFinder *finder = new KeyFinder(det_w->getName());
    keys = finder->generate();
    QString key;
    foreach(key,keys)   {
        engine->addEntry(key,index_item);
    }
    engine->saveIndex();
    model->deleteLater();
    id_gen->deleteLater();
    xml->deleteLater();
    engine->deleteLater();
    finder->deleteLater();

    close();
    }
}
