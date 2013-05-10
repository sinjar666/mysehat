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

#include "addallergenwid.h"

AddAllergenWid::AddAllergenWid(QString rootdir, QWidget *parent) :
    QWidget(parent)
{
    path = rootdir;
    u = new upper();
    m=new Middle();
    b=new bottom();
    layout = new QVBoxLayout(this);
    layout->addWidget(u);
    layout->addWidget(m);
    layout->addWidget(b);
    connect(b,SIGNAL(savePressed()),this,SLOT(performSave()));
    connect(b,SIGNAL(resetPressed()),this,SLOT(performReset()));
}


void AddAllergenWid::performReset() {
    u->resetAll();
}

void AddAllergenWid::performSave()  {
    //Note this sequence of steps that is to be followed
    //First we must declare a model object
    if(u->getName().isEmpty())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("Please enter the allergen name"));
    }
    else
    {
    Allergen *model;

    //and initialize it
    model = new Allergen();

    //Then we should generate an id for this model object
    //the id acts as the file name for saving the model
    IdGen *id_gen; //declare
    id_gen = new IdGen(path); //initialize
    QString id = id_gen->generate(IdGen::ALLERGEN_T); //generate
    //Now we have the id in the variable "id"
    //Add the root path before the id so as to have a complete absolute path
    //id = path + id;

    //Next fill the model with the data from the UI
    model->setDate(QDate::currentDate()); //date is today
    model->setName(u->getName()); //Get name from the getName() in u that is an object of upper
    model->setType(m->getType()); //Get the type likewise from middle
    //Now the model is ready

    //Save the file using the xml engine
    XAllergen *xml = new XAllergen(model,id); //initialize by giving model and the complete path
    xml->saveData(); //perform the save

    //Now add it to the search engine
    IndexItem index_item(QDate::currentDate(),id,2,QString()); //create the index item
    //see indexitem.h for details about the type (third) argument
    Engine *engine = new Engine(path+"/"); //Initialize the engine by giving it the root path
    engine->loadIndex(); //Load the index file into the engine
    //We need keywords to be generated from the name of the allergen right..
    QStringList keys;
    KeyFinder *keygen = new KeyFinder(u->getName()); //initialize the generator by giving it the text to generate the keywords from
    keys = keygen->generate(); //generate the keywords
    qDebug() << keys;
    //For every keyword have an entry in the search index
    QString key;
    foreach(key,keys)  {
        engine->addEntry(key,index_item);
    }
    //Dont forget to save the index ;)
    engine->saveIndex();

    //Now that the work is done perform the cleanup
    //delete the items we allocated on the heap but did not parent
    model->deleteLater();
    id_gen->deleteLater();
    xml->deleteLater();
    engine->deleteLater();
    keygen->deleteLater();

    // now close your widget
    close();

    //that is all...
    }
}
