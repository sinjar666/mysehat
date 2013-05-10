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

#include "fatalnotavail.h"

FatalNotAvail::FatalNotAvail(QString path, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    lay = new QHBoxLayout(this);
    msg = new QLabel(QString("The root directory ")+path+QString(" is not ready or writeable. Ensure that the device is available before proceeding. If you have deleted the root directory you must reset the app. Press Reset to do that and exit..."));
    msg->setWordWrap(true);
    button = new QPushButton(tr("Exit"));
    reset = new QPushButton(tr("Reset"));
    lay->addWidget(msg);
    lay->addWidget(reset);
    lay->addWidget(button);
    connect(button,SIGNAL(clicked()),this,SLOT(accept()));
    connect(reset,SIGNAL(clicked()),this,SLOT(resetApp()));
}

void FatalNotAvail::resetApp()  {
    QFile t(tr("/home/user/.isbnkeeper-config"));
    t.remove();
    accept();
}
