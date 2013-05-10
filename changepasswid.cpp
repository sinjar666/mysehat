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

#include "changepasswid.h"

ChangePassWid::ChangePassWid(QString currentuser,QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("Reset Password ");
    curr_user=currentuser;
    g_layout=new QGridLayout(this);
    old_l=new QLabel("Old Password");
    new_l=new QLabel("New Password");
    retype_l=new QLabel("Retype Password");
    old_e=new QLineEdit();
    old_e->setEchoMode(QLineEdit::Password);
    new_e=new QLineEdit();
    new_e->setEchoMode(QLineEdit::Password);
    retype_e=new QLineEdit();
    retype_e->setEchoMode(QLineEdit::Password);
    ok_button=new QPushButton("Done");

    g_layout->addWidget(old_l,0,0);
    g_layout->addWidget(old_e,0,1);
    g_layout->addWidget(new_l,1,0);
    g_layout->addWidget(new_e,1,1);
    g_layout->addWidget(retype_l,2,0);
    g_layout->addWidget(retype_e,2,1);
    g_layout->addWidget(ok_button,3,0);
    g_layout->addWidget(new QLabel(),3,1);

    connect(ok_button,SIGNAL(clicked()),this,SLOT(passauth()));
}

void ChangePassWid::passauth()
{
    if(new_e->text()!=retype_e->text())
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("The new and the retyped passwords do not match"));
    }
    PassMan *pass_man=new PassMan("/home/user/.config/.sehatpass");
    pass_man->loadPassList();
    if(!pass_man->checkPass(curr_user,old_e->text()))
    {
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("The password is wrong...Try Again"));
    }
    else
    {
        pass_man->removePass(curr_user);
        pass_man->addPass(curr_user,new_e->text());
        QErrorMessage *mesg=new QErrorMessage(this);
        mesg->showMessage(tr("The password was successfully changed"));
    }
}
