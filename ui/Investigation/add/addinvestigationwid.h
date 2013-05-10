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
