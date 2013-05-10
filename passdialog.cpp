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

#include "passdialog.h"

PassDialog::PassDialog(QString user_a, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    setWindowTitle(tr("Enter password"));
    curr_user=user_a;
    h_layout=new QHBoxLayout(this);

    pass_l=new QLabel("Password");
    pass_e=new QLineEdit();
    pass_e->setEchoMode(QLineEdit::Password);
    done_button=new QPushButton("Log In");

    h_layout->addWidget(pass_l);
    h_layout->addWidget(pass_e);
    h_layout->addWidget(done_button);
    connect(done_button,SIGNAL(clicked()),this,SLOT(button_clicked()));
}

void PassDialog::button_clicked()
{
    PassMan *pass_man=new PassMan("/home/user/.config/.sehatpass");
    pass_man->loadPassList();
    //qDebug()<<"Curr user=" << curr_user;
    if(pass_man->checkPass(curr_user,pass_e->text()))
       accept();
    else
       reject();
}
