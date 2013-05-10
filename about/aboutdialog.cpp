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

#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("About mySEHAT"));
    setModal(false);
    text_v = new QTextBrowser();
    text_v->setOpenLinks(false);
    QFile fil(tr(":about/aboutpage.html"));
    if(!fil.open(QIODevice::ReadOnly))
        qDebug("cant open about file");
    QTextStream stream(&fil);
    QString msg;
    msg=stream.readAll();
    text_v->setHtml(msg);
    icon_l = new QLabel();
    icon_l->setPixmap(QPixmap::fromImage(QImage(tr(":icons/bigicon.jpg")).scaled(200,200)));
    icon_l->setFixedHeight(300);

    lay = new QHBoxLayout(this);
    lay->addWidget(text_v);
    lay->addWidget(icon_l);
}
