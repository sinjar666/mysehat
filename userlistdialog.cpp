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

#include "userlistdialog.h"

UserListDialog::UserListDialog(QDir *pathdir_a,QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("Select a user"));
    pathdir=pathdir_a;
    //qDebug()<<pathdir->absolutePath();
    setWindowTitle(tr("User List"));
    setModal(true);
    vlayout = new QVBoxLayout(this);
    mesg = new QLabel(tr("Tap to choose user"));
    list_users = new QListWidget();
    Config *config_users=new Config(pathdir->absolutePath()+"/");
    QStringList user_list;
    user_list=config_users->userlist();
    //qDebug()<<user_list;

        list_users->addItems(user_list);
        vlayout->addWidget(list_users);
        connect(list_users,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onUserClick(QListWidgetItem*)));

}

void UserListDialog::onUserClick(QListWidgetItem *item)
{
    pathdir->cd(item->text());
    emit catchcurruser(item->text());
    accept();
}
