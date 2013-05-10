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

#include "editallergenwid.h"

EditAllergenWid::EditAllergenWid(QString rootdir, IndexItem olditem_a, QWidget *parent) :
    QWidget(parent)
{
    //model_old = model_a;
    old_item=olditem_a;
    path = rootdir;
    model = new Allergen();
    XAllergen *xml = new XAllergen(model,old_item.getLocation());
    xml->readData();
    u = new EditUpper(model->getName());
    old=model->getName();
    m=new EditMiddle();
    m->setType(model->getType());
    b=new EditBottom();
    layout = new QVBoxLayout(this);
    layout->addWidget(u);
    layout->addWidget(m);
    layout->addWidget(b);
    connect(b,SIGNAL(resetPressed()),this,SLOT(performReset()));
    connect(b,SIGNAL(savePressed()),this,SLOT(performSave()));

}


void EditAllergenWid::performReset() {
    u->resetAll();
}

void EditAllergenWid::performSave()  {

    //Next fill the model with the data from the UI
    if(u->getName().isEmpty())
    {
        qDebug("ghusa");
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the name of the allergen"));
    }
    else
    {
    model->setDate(QDate::currentDate()); //date is today
    model->setName(u->getName()); //Get name from the getName() in u that is an object of upper
    model->setType(m->getType()); //Get the type likewise from middle
    //Now the model is ready

    //Save the file using the xml engine
    XAllergen *xml = new XAllergen(model,old_item.getLocation()); //initialize by giving model and the complete path
    xml->saveData(); //perform the save
    //Remove the old index entries and add new to search engine
    Engine *engine = new Engine(path); //Initialize the engine by giving it the root path
    engine->loadIndex(); //Load the index file into the engine
    KeyFinder *keyfinder = new KeyFinder(old);
    QStringList keys;
    QString key;
    keys=keyfinder->generate();
    foreach(key,keys)   {
        engine->remove(key,old_item);
    }

    //Now add it to the search engine
    IndexItem index_item(QDate::currentDate(),old_item.getLocation(),2,old_item.getDisease()); //create the index item
    //see indexitem.h for details about the type (third) argument

    //We need keywords to be generated from the name of the allergen right..

    keyfinder = new KeyFinder(u->getName()); //initialize the generator by giving it the text to generate the keywords from
    keys = keyfinder->generate(); //generate the keywords
    //For every keyword have an entry in the search index

    foreach(key,keys)  {
        engine->addEntry(key,index_item);
    }
    //Dont forget to save the index ;)
    engine->saveIndex();

    //Now that the work is done perform the cleanup
    //delete the items we allocated on the heap but did not parent
    model->deleteLater();
    //id_gen->deleteLater();
    xml->deleteLater();
    engine->deleteLater();
    //keygen->deleteLater();

    // now close your widget
    close();

    //that is all...
    }
}
