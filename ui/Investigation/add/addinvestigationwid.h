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

#ifndef ADDINVESTIGATIONWID_H
#define ADDINVESTIGATIONWID_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QDate>
#include <QTextEdit>
#include <QLineEdit>
#include <QStringList>
#include <QErrorMessage>
#include <QFileDialog>

#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "KeyFinder/keyfinder.h"
#include "IdGen/idgen.h"
#include "model/investigation.h"
#include "xml/Investigation/xinvestigation.h"

#include "stillcam/stillcam.h"

class AddInvestigationWid : public QWidget
{
    Q_OBJECT
    QString path,img_path;
    QGridLayout *g_layout;
    QLabel *datetime,*type,*detail_l,*report;
    QTextEdit *details;
    QComboBox *dropdown;
    QDateTimeEdit *date_t;
    QPushButton *imagepath,*save,*reset,*browse_b;

    Investigation *model;
    StillCam *camera_wid;

public:
    explicit AddInvestigationWid(QString rootdir,QWidget *parent = 0);

signals:

public slots:
    void reset_function();
    void perform_save();
    void imagevideo();
    void browseClicked();

};

#endif // ADDINVESTIGATIONWID_H
