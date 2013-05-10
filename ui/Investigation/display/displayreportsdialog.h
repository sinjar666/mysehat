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

#ifndef DISPLAYREPORTSDIALOG_H
#define DISPLAYREPORTSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QImage>
#include <QPixmap>

class DisplayReportsDialog : public QWidget
{
    Q_OBJECT
    QString path;
    QLabel *img_wid;
    QHBoxLayout *lay;

public:
    explicit DisplayReportsDialog(QString path_a, QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DISPLAYREPORTSDIALOG_H
