#ifndef EDITINVESTIGATIONWID_H
#define EDITINVESTIGATIONWID_H

#include <QWidget>
#include <QString>
#include <QGridLayout>
#include <QLabel>
#include <QDateEdit>
#include <QTimeEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QErrorMessage>
#include <QFileDialog>

#include "xml/Investigation/xinvestigation.h"
#include "search-engine/engine/engine.h"
#include "search-engine/engine/indexitem.h"
#include "model/investigation.h"
#include "KeyFinder/keyfinder.h"
#include "stillcam/stillcam.h"

class EditInvestigationWid : public QWidget
{
    Q_OBJECT
    QGridLayout *g_layout;
    XInvestigation *xml;
    Investigation *model;
    QString path,img_path;
    QLabel *date_l,*time_l,*type_l,*detail_l,*report_l;
    IndexItem old_item;
    QDateEdit *date_e;
    QTimeEdit *time_e;
    QPushButton *save_b,*reset_b,*report_b,*browse_b;
    QComboBox *type_c;
    QTextEdit *detail_e;
    StillCam *camera_wid;

public:
    explicit EditInvestigationWid(QString path_a,IndexItem olditem,QWidget *parent = 0);

signals:

public slots:
    void perform_reset();
    void perform_save();
    void perform_camera();
    void perform_browse();

};

#endif // EDITINVESTIGATIONWID_H
