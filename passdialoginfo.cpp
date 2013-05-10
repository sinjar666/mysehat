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

#include "passdialoginfo.h"

PassDialogInfo::PassDialogInfo(bool status, QWidget *parent) :
    QDialog(parent)
{
    h_layout=new QHBoxLayout(this);
    ok_button=new QPushButton("OK");
    if(status)
    {
        t_message=new QLabel(tr("You have been successfully logged in"));
        h_layout->addWidget(t_message);
    }
    else
    {
        f_message=new QLabel(tr("The password is wrong..Try again"));
        h_layout->addWidget(f_message);
    }
    h_layout->addWidget(ok_button);
    connect(ok_button,SIGNAL(clicked()),this,SLOT(accept()));
}
