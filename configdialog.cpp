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

#include "configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    setWindowTitle(QString("Configure root directory"));
    fil = new QFile("/home/user/.mysehat-config");
    if(!fil->open(QIODevice::ReadOnly)) {
        qDebug("no config");

    }
    QTextStream stream(fil);
    QString path;
    stream >> path;
    fil->close();
    path_e = new QLineEdit(path);
    path_e->setReadOnly(true);
    browse_b = new QPushButton(tr("Browse."));
    lay = new QHBoxLayout(this);
    lay->addWidget(path_e);
    lay->addWidget(browse_b);
    connect(browse_b,SIGNAL(clicked()),this,SLOT(chooseFile()));
}

void ConfigDialog::chooseFile() {
    QString path = QFileDialog::getExistingDirectory(this,tr("Choose a root directory"),path_e->text());
    if(!path.endsWith("/"))
        path+="/";
//    QProcess process;
//    if(path_e->text()!=path)  {
//        process.execute(QString("cp ")+path_e->text()+tr("*.xml ")+path);
//        process.execute(QString("mv ")+path_e->text()+tr("index ")+path);
//    }
    if(!fil->open(QIODevice::WriteOnly|QIODevice::Truncate))
            qWarning("Unable to update config file.");
        QTextStream stream(fil);
        stream << path;
        path_e->setText(path);
        fil->close();
        fil->setFileName(path+"tester");
        if(fil->open(QIODevice::WriteOnly)) {
            fil->remove();
            accept();
        }
        else
            reject();
}
