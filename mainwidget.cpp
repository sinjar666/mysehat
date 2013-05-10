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

#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    engine=NULL;
    QFile fil(tr("/home/user/.mysehat-config"));
    if(!fil.open(QIODevice::ReadOnly))
    {
        ConfigDialog *config_dialog = new ConfigDialog(this);
        status=config_dialog->exec();
        if(!status)
        {
            FatalMessage *mesg=new FatalMessage(this);
            mesg->exec();
            exit(1);
        }
    }
    fil.close();
    fil.open(QIODevice::ReadOnly);
    QTextStream stream(&fil);
    QString path;
    stream>>path;
    fil.close();

    pathdir =new QDir(path);
    //qDebug() << path + "config.xml";
    fil.setFileName(path+"config.xml");

    if(!fil.open(QIODevice::ReadOnly))
    {
        bool flag=false;
        newuser = new NewUserDialog(pathdir,this);
        connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
        if(!(flag=newuser->exec()))    {
            //Display error and exit
            QMessageBox::warning(this,tr("My Sehat"),tr("You must create a new user in order to proceed. The application will now close"));
            exit(2);
        }
        connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
        newuser->deleteLater();
    }
    else
    {
        Config *conf = new Config(pathdir->absolutePath()+"/");
        QStringList user_list;
        user_list = conf->userlist();
        if(user_list.length()>0)    {
            bool flag=false;
            userlist=new UserListDialog(pathdir,this);
            connect(userlist,SIGNAL(catchcurruser(QString)),this,SLOT(catchuserevent(QString)));
            if(!(flag=userlist->exec()))
            {
                //Display error
                QMessageBox::warning(this,tr("My Sehat"),tr("You must choose a user in order to proceed. The application will close now"));
                exit(3);
            }
            connect(userlist,SIGNAL(catchcurruser(QString)),this,SLOT(catchuserevent(QString)));
            userlist->deleteLater();
        }
        else    {
            system("rm /home/user/.config/.sehatpass");
            bool flag=false;
            newuser = new NewUserDialog(pathdir,this);
            connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
            if(!(flag=newuser->exec()))    {
                //Display error and exit
                QMessageBox::warning(this,tr("My Sehat"),tr("You must create a new user in order to proceed. The application will now close."));
                exit(2);
            }
            connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
            newuser->deleteLater();
        }
    }

    menu_bar =new QMenuBar(this);
    menu_bar->addAction(QString("New User"));
    menu_bar->addAction(QString("Switch User"));
    menu_bar->addAction(QString("Add Details"));
    menu_bar->addAction(QString("Delete User"));
    menu_bar->addAction(QString("Change Password"));
    menu_bar->addAction(QString("About"));


    engine = new Engine(pathdir->absolutePath()+"/");
    engine->loadIndex();

    path_value=getappointmentlist();

    results = new QList<IndexItem>();
    w= new SearchWidget();
    w2 = new ItemList(pathdir->absolutePath()+"/",engine);
    area=new QScrollArea();

    QList<AppointmentButton *>button_list;
    for(int i=0;i<path_value.size();i++)
    {
        AppointmentButton *abutton=new AppointmentButton(path_value[i]);
        connect(abutton,SIGNAL(AppointItemClicked(QString)),this,SLOT(appointtriggered(QString)));
        button_list.append(abutton);
    }
    app_list = new AppointmentList(button_list);
   // area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //area->setWidget(w2);
    layout = new QVBoxLayout(this);
    layout->addWidget(w);
    layout->addWidget(area);
    area->setWidget(app_list);
    searchmode=false;

    setLayout(layout);

    connect(w,SIGNAL(searchPressed()),this,SLOT(performSearch()));
    connect(w,SIGNAL(filter()),this,SLOT(displayFilterDialog()));
    connect(menu_bar,SIGNAL(triggered(QAction*)),this,SLOT(menutriggered(QAction*)));
}

MainWidget::~MainWidget()   {
   delete(results);
}

void MainWidget::paintEvent(QPaintEvent *event) {
    if(engine && searchmode)  {
        engine->loadIndex();
    }
    setWindowTitle(QString("My SEHAT -- ")+ curr_user);
}

void MainWidget::performSearch()    {
    if(w->getKey().isEmpty())   {
        return;
    }
    searchmode=true;
    QList<ItemButton *> l;
    QString description;
    IndexItem item;
    results->clear();
    results->append(engine->getEntry(w->getKey()));
    results->append(engine->getSubstringMatch(w->getKey()));
    //Remove duplicates
    foreach(item,*results)   {
        int c=results->count(item);
        if(c>1) {
            results->removeAll(item);
            results->append(item);
        }
    }

    if(results->length()==0)
    {
        QLabel *no_item=new QLabel("<font size=\"20\">&nbsp; No Item was found </font>");
        area->setWidget(no_item);
    }
    //qDebug() << w->getKey();
    //qDebug() << results->length();
    else
    {
    foreach(item,*results)  {
        ItemButton::InvestigationType st=ItemButton::Other;
        ItemButton::ItemType t;
        switch((int)item.getType()) {
        case 0: {
            t=ItemButton::Appointment;
            Appointment *model=new Appointment();
            XAppointment *app_data=new XAppointment(model,item.getLocation());
            app_data->readData();
            description=model->getName();
            break;
        }
        case 1:
        {
            t=ItemButton::Symptom;
            Symptom *model=new Symptom();
            XSymptom *app_data=new XSymptom(model,item.getLocation());
            app_data->readData();
            description=model->getDescription();
            break;
        }
        case 2:
        {
            t=ItemButton::Allergen;
            Allergen *model=new Allergen();
            XAllergen *app_data=new XAllergen(model,item.getLocation());
            app_data->readData();
            description=model->getName();
            break;
        }
        case 3:
        {
            t=ItemButton::Drug;
            Drug *model=new Drug();
            XDrug *app_data=new XDrug(model,item.getLocation());
            app_data->readData();
            description=model->getName();
            break;
        }
        case 4:
        {
            t=ItemButton::Investigation;
            Investigation *model=new Investigation();
            XInvestigation *app_data=new XInvestigation(model,item.getLocation());
            app_data->readData();
            description=model->getDetails();
            st = (ItemButton::InvestigationType) model->getType();
            break;
        }
        case 5:
        {
            t=ItemButton::Surgery;
            Surgery *model=new Surgery();
            XSurgery *app_data=new XSurgery(model,item.getLocation());
            app_data->readData();
            description=model->getDetails();
            break;
        }
        case 6:
        {
            t=ItemButton::FamilyHistory;
            FamilyHistory *model=new FamilyHistory();
            XFamilyHistory *app_data=new XFamilyHistory(model,item.getLocation());
            app_data->readData();
            description=model->getName();
            break;
        }
        default:
        {
            t=ItemButton::Vaccine;
            Vaccine *model=new Vaccine();
            XVaccine *app_data=new XVaccine(model,item.getLocation());
            app_data->readData();
            description=model->getName();
            break;
        }
        }
//        qDebug() << (int)t;
//        qDebug() << item.getDisease();

        l.append(new ItemButton(pathdir->absolutePath()+"/",engine,new IndexItem(item),w->getKey(),t,description,st,item.getDate(),item.getDisease()));
    }
    delete(area->takeWidget());
    w2 = new ItemList(pathdir->absolutePath()+"/",engine,l);
    area->setWidget(w2);
    connect(w2,SIGNAL(triggerOpen(QString,ItemButton::ItemType)),this,SLOT(displayItemDetails(QString,ItemButton::ItemType)));
    connect(w2,SIGNAL(triggerEdit(IndexItem)),this,SLOT(editItemDetails(IndexItem)));
    connect(w2,SIGNAL(triggerDisease(IndexItem)),this,SLOT(showLinkDisease(IndexItem)));
    connect(w2,SIGNAL(triggerDelete(IndexItem,ItemButton *)),this,SLOT(performDelete(IndexItem,ItemButton *)));

    }
}

void MainWidget::displayFilterDialog()  {
    dialog = new FilterDialog(engine,engine->getFilters(),this);
    dialog->exec();
    delete(dialog);
    performSearch();
}

void MainWidget::displayItemDetails(QString loc,ItemButton::ItemType type)
{
    //qDebug() << "Displaying" << loc << type;
    //display the correct item as stacked window
    switch((int)type)
    {
    case 0:
    {
        Appointment *model=new Appointment();
        XAppointment *xml_data=new XAppointment(model,loc);
        xml_data->readData();
        DisplayAppointmentWid *disp_wid=new DisplayAppointmentWid(true,model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml_data->deleteLater();
        //model->deleteLater();
        break;
    }
    case 1:
    {
        Symptom *model=new Symptom();
        XSymptom *xml=new XSymptom(model,loc);
        xml->readData();
        DisplaySymptomWid *disp_wid=new DisplaySymptomWid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    case 2:
    {
        //qDebug() << "here";
        Allergen *model=new Allergen();
        XAllergen *xml = new XAllergen(model,loc);
        xml->readData();
        DisplayAllergenWid *disp_wid=new DisplayAllergenWid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    case 3:
    {
        Drug *model=new Drug();
        XDrug *xml=new XDrug(model,loc);
        xml->readData();
        DisplayDrugWid *disp_wid=new DisplayDrugWid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    case 4:
    {
        Investigation *model=new Investigation();
        XInvestigation *xml=new XInvestigation(model,loc);
        xml->readData();
        DisplayInvestigationwid *disp_wid=new DisplayInvestigationwid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    case 5:
    {
        Surgery *model= new Surgery();
        XSurgery *xml=new XSurgery(model,loc);
        xml->readData();
        DisplaySurgeryWid *disp_wid=new DisplaySurgeryWid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    case 6:
    {
        FamilyHistory *model=new FamilyHistory();
        XFamilyHistory *xml=new XFamilyHistory(model,loc);
        xml->readData();
        DisplayFamilyHistoryWid *disp_wid=new DisplayFamilyHistoryWid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    case 7:
    {
        Vaccine *model=new Vaccine();
        XVaccine *xml=new XVaccine(model,loc);
        xml->readData();
        DisplayVaccineWid *disp_wid=new DisplayVaccineWid(model,this);
        disp_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        disp_wid->setAttribute(Qt::WA_DeleteOnClose);
        disp_wid->setWindowFlags(disp_wid->windowFlags()|Qt::Window);
        disp_wid->show();
        //xml->deleteLater();
        //model->deleteLater();
        break;
    }
    }
 }

void MainWidget::menutriggered(QAction *action)
{
    if(action->text()=="New User")
    {    //New User dialog
        QString tmp = pathdir->absolutePath();
        pathdir->cdUp();
        newuser = new NewUserDialog(pathdir,this);
        connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
        if(!newuser->exec())    {
            pathdir->setPath(tmp);
            //qDebug() << pathdir->absolcatchcurruserutePath();
        }
        //qDebug() << x;
        newuser->deleteLater();
    }

    if(action->text()=="Switch User")
    {    //Switch user class
        QString tmp = pathdir->absolutePath();
        pathdir->cdUp();
        userlist = new UserListDialog(pathdir,this);
        connect(userlist,SIGNAL(catchcurruser(QString)),this,SLOT(catchuserevent(QString)));
        if(!userlist->exec())
            pathdir->setPath(tmp);
        userlist->deleteLater();
    }

    if(action->text()=="Add Details")
    {    //add details class
        menu_bar->hide();
        if(!log_value)  {
            PassDialog *pd = new PassDialog(curr_user,this);
            pa_stat = pd->exec();

        if(pa_stat) {
            log_value=true;
            PassDialogInfo *pass_info=new PassDialogInfo(true);
            pass_info->exec();
        }
        else    {
            log_value=false;
            PassDialogInfo *pass_info=new PassDialogInfo(false);
            pass_info->exec();
        }
        }
        if(log_value)   {
            AddItemWidget *add_item=new AddItemWidget(pathdir,this);
            add_item->setAttribute(Qt::WA_Maemo5StackedWindow);
            add_item->setAttribute(Qt::WA_DeleteOnClose);
            add_item->setWindowFlags(add_item->windowFlags()|Qt::Window);
            add_item->show();
        }
    }
    if(action->text()=="About")
    {    //about class
        AboutDialog *about_wid=new AboutDialog(this);
        about_wid->exec();
    }
    if(action->text()=="Delete User")   {
        pathdir->cdUp();
        UserListDialog *ud = new UserListDialog(pathdir,this);
        connect(ud,SIGNAL(catchcurruser(QString)),this,SLOT(performUserDel(QString)));
        if(!ud->exec())
            pathdir->cd(curr_user);

    }
    if(action->text()=="Change Password")
    {
        ChangePassWid *change_wid=new ChangePassWid(curr_user,this);
        change_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
        change_wid->setAttribute(Qt::WA_DeleteOnClose);
        change_wid->setWindowFlags(change_wid->windowFlags()|Qt::Window);
        change_wid->show();
    }
}

QList<QString> MainWidget::getappointmentlist()
{
    QFile fil(pathdir->absolutePath()+"/appoint_list");
    if(!fil.open(QIODevice::ReadOnly))
        qDebug("Unable to open appoint_list file for the first time");
    else
    {
        QDataStream out(&fil);
        out >> map_date;
    }
    fil.close();
    QDate select_date=QDate::currentDate();
    QList<QString> path_values;
    for(int i=0;i<31;i++)
    {
        path_values.append(map_date.values(select_date));
        select_date=select_date.addDays(1);
    }
    //qDebug()<<path_values.size();
    return path_values;
}

void MainWidget::appointtriggered(QString path_arg)
{
    Appointment *model=new Appointment(this);
    XAppointment *xml_data=new XAppointment(model,path_arg,this);
    xml_data->readData();
    DisplayAppointmentWid *app_display=new DisplayAppointmentWid(true,model,this);
    app_display->setAttribute(Qt::WA_Maemo5StackedWindow);
    app_display->setAttribute(Qt::WA_DeleteOnClose);
    app_display->setWindowFlags(app_display->windowFlags()|Qt::Window);
    app_display->show();
    //xml_data->deleteLater();
    //model->deleteLater();
}

void MainWidget::editItemDetails(IndexItem item)    {
    ItemButton::ItemType type = (ItemButton::ItemType)item.getType();
    if(!log_value)  {
        PassDialog *pd = new PassDialog(curr_user,this);
        pa_stat = pd->exec();

    if(pa_stat) {
        log_value=true;
        PassDialogInfo *pass_info=new PassDialogInfo(true);
        pass_info->exec();
    }
    else    {
        log_value=false;
        PassDialogInfo *pass_info=new PassDialogInfo(false);
        pass_info->exec();
    }
    }
    if(log_value)
    {
        switch(type)
        {
            case ItemButton::Symptom:
            {
                EditSymptomWid *edit_wid=new EditSymptomWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::Appointment:
            {
                EditAppointmentWid *edit_wid=new EditAppointmentWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::Surgery:
            {
                EditSurgeryWid *edit_wid=new EditSurgeryWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::FamilyHistory:
            {
                EditFamilyHistoryWid *edit_wid=new EditFamilyHistoryWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::Allergen:
            {
                EditAllergenWid *edit_wid=new EditAllergenWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::Investigation:
            {
                EditInvestigationWid *edit_wid=new EditInvestigationWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::Drug:
            {
                EditDrugWid *edit_wid=new EditDrugWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
            case ItemButton::Vaccine:
            {
                EditVaccineWid *edit_wid=new EditVaccineWid(pathdir->absolutePath()+"/",item,this);
                edit_wid->setAttribute(Qt::WA_Maemo5StackedWindow);
                edit_wid->setAttribute(Qt::WA_DeleteOnClose);
                edit_wid->setWindowFlags(edit_wid->windowFlags()|Qt::Window);
                connect(edit_wid,SIGNAL(destroyed()),this,SLOT(performSearch()));
                edit_wid->show();
                break;
            }
        }
    }

}

void MainWidget::showLinkDisease(IndexItem item)
{
    disease.clear();
    olditem=item;
    LinkDiseaseDialog *link_dialog = new LinkDiseaseDialog(pathdir->absolutePath()+"/",&disease,item.getLocation(),this);
    connect(link_dialog,SIGNAL(accepted()),this,SLOT(performLinkDisease()));
    link_dialog->exec();
}

void MainWidget::performLinkDisease()
{
    QList<QString> l;
    l=engine->getKeys(olditem);
    //qDebug() << disease;
    IndexItem newItem(olditem.getDate(),olditem.getLocation(),olditem.getType(),disease);
    QString i;
    foreach(i,l)    {
        engine->remove(i,olditem);
        engine->addEntry(i,newItem);
    }
    engine->saveIndex();
}

void MainWidget::catchuserevent(QString user)
{
    curr_user=user;
    if(engine)  {
        engine->deleteLater();
        engine = new Engine(pathdir->absolutePath()+"/");
        performSearch();
    }
    log_value=false;
    setWindowTitle(QString("My SEHAT -- ")+curr_user);
}

void MainWidget::performDelete(IndexItem item,ItemButton *obj)    {
    if(!log_value)  {
        PassDialog *pd = new PassDialog(curr_user,this);
        pa_stat = pd->exec();
        if(pa_stat) {
            log_value=true;
            PassDialogInfo *pass_info=new PassDialogInfo(true);
            pass_info->exec();
        }
        else    {
            log_value=false;
            PassDialogInfo *pass_info=new PassDialogInfo(false);
            pass_info->exec();
        }
    }
    if(log_value)   {
        int ret=QMessageBox::warning(this,tr("My SEHAT"),tr("Would you like to delete the selected item?"),
                             QMessageBox::Yes,QMessageBox::No);
        if(ret==QMessageBox::Yes)   {
            DeleteWid *delete_wid=new DeleteWid(pathdir->absolutePath(),item);
            delete_wid->deleteLater();
            QMessageBox::information(this,tr("My Sehat"),tr("File was successfully deleted."));
            obj->hide();
        }
    }
}

void MainWidget::performUserDel(QString user)   {
            PassDialog *pd = new PassDialog(user,this);
            pa_stat = pd->exec();
            if(pa_stat) {
                log_value=true;
                PassDialogInfo *pass_info=new PassDialogInfo(true);
                pass_info->exec();
            }
            else    {
                log_value=false;
                PassDialogInfo *pass_info=new PassDialogInfo(false);
                pass_info->exec();
            }

    if(log_value)   {
        log_value=false;
    int ret=QMessageBox::warning(this,tr("My SEHAT"),tr("Would you like to delete the selected user?"),
                                 QMessageBox::Yes,QMessageBox::No);
    if(ret==QMessageBox::Yes)   {
        pathdir->cdUp();
        pathdir->cd(user);
        QString cmd = QString("rm -Rf ") + pathdir->absolutePath() + "/*";
        if(!system(cmd.toAscii().data())) {
            qDebug("delete user failed.");
        }
        pathdir->cdUp();
        pathdir->rmdir(user);
        Config *conf = new Config(pathdir->absolutePath()+"/");
        conf->deluser(user);
        PassMan *man = new PassMan(tr("/home/user/.config/.sehatpass"));
        man->loadPassList();
        man->removePass(user);
        man->savePassList();
        man->deleteLater();
        QMessageBox::information(this,tr("My SEHAT"),tr("User was deleted successfully."));
        if(curr_user==user) {
            Config *conf = new Config(pathdir->absolutePath()+"/");
            QStringList user_list;
            user_list = conf->userlist();
            if(user_list.length()>0)    {
                bool ret=false;
                UserListDialog *ud = new UserListDialog(pathdir,this);
                connect(ud,SIGNAL(catchcurruser(QString)),this,SLOT(catchuserevent(QString)));
                while(!ret) {
                ret=ud->exec();
                }
            }
            else    {
                system("rm /home/user/.config/.sehatpass");
                bool flag=false;
                newuser = new NewUserDialog(pathdir,this);
                connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
                if(!(flag=newuser->exec()))    {
                    //Display error and exit
                    QMessageBox::warning(this,tr("My SEHAT"),tr("You must create a new user in order to proceed. The application will now close"));
                    exit(2);
                }
                connect(newuser,SIGNAL(username(QString)),this,SLOT(catchuserevent(QString)));
                newuser->deleteLater();
            }
        }
        else    {
            pathdir->cd(curr_user);
        }
    }
    }
}
