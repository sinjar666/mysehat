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

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QDebug>
#include <QDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QErrorMessage>
#include <QMenuBar>
#include <QDataStream>
#include <QMultiMap>
#include <QLabel>
#include <QMessageBox>

#include "search-engine/searchwidget.h"
#include "search-engine/itemlist.h"
#include "search-engine/widgets/filterdialog.h"
#include "configdialog.h"
#include "fatalmessage.h"
#include "config/config.h"
#include "newuserdialog.h"
#include "userlistdialog.h"
#include "adddetails/additemwidget.h"
#include "appointmentlist.h"
#include "appointmentbutton.h"

#include "model/appointment.h"
#include "model/allergen.h"
#include "model/drug.h"
#include "model/familyhistory.h"
#include "model/investigation.h"
#include "model/surgery.h"
#include "model/symptom.h"
#include "model/vaccine.h"

#include "xml/Appointment/xappointment.h"
#include "xml/Allergen/xallergen.h"
#include "xml/Drug/xdrug.h"
#include "xml/FamilyHistory/xfamilyhistory.h"
#include "xml/Investigation/xinvestigation.h"
#include "xml/Surgery/xsurgery.h"
#include "xml/Symptom/xsymptom.h"
#include "xml/Vaccine/xvaccine.h"

#include "ui/Appointment/display/displayappointmentwid.h"
#include "ui/Allergen/display/displayallergenwid.h"
#include "ui/Drug/display/displaydrugwid.h"
#include "ui/FamilyHistory/display/displayfamilyhistorywid.h"
#include "ui/Investigation/display/displayinvestigationwid.h"
#include "ui/Surgery/display/displaysurgerywid.h"
#include "ui/Symptom/display/displaysymptomwid.h"
#include "ui/Vaccine/display/displayvaccinewid.h"

#include "about/aboutdialog.h"
#include "passdialog.h"
#include "passdialoginfo.h"
#include "deletewid.h"
#include "changepasswid.h"

class MainWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *layout;
    QScrollArea *area;
    QList<QString> path_value;
    SearchWidget *w;
    ItemList *w2;
    QList<IndexItem> *results;
    Engine *engine;
    FilterDialog *dialog;
    QString curr_user;
    QDir *pathdir;
    bool status;
    NewUserDialog *newuser;
    UserListDialog *userlist;
    QMenuBar *menu_bar;
    QMultiMap<QDate,QString> map_date;
    AppointmentList *app_list;
    QString disease;
    IndexItem olditem;
    bool log_value,pa_stat,searchmode;
protected:
    void paintEvent(QPaintEvent *event);
public:
    explicit MainWidget(QWidget *parent = 0);
    QList<QString> getappointmentlist();
    ~MainWidget();
private:

signals:

public slots:
    void performSearch();
    void displayFilterDialog();
    void displayItemDetails(QString loc,ItemButton::ItemType type);
    void menutriggered(QAction *action);
    void appointtriggered(QString path_arg);
    void editItemDetails(IndexItem item);
    void showLinkDisease(IndexItem item);
    void performLinkDisease();
    void performDelete(IndexItem item, ItemButton *obj);
    void catchuserevent(QString user);
    void performUserDel(QString user);
};

#endif // MAINWIDGET_H
