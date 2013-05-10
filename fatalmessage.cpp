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

#include "fatalmessage.h"

FatalMessage::FatalMessage(QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    lay = new QHBoxLayout(this);
    msg = new QLabel(tr("You MUST specify a VALID root directory for the application to function. Restart application and specify a VALID root directory. Exiting now"));
    msg->setWordWrap(true);
    okButton = new QPushButton(tr("Exit"));
    lay->addWidget(msg);
    lay->addWidget(okButton);
    connect(okButton,SIGNAL(clicked()),this,SLOT(accept()));
}
