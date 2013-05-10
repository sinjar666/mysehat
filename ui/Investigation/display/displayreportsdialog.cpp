#include "displayreportsdialog.h"

DisplayReportsDialog::DisplayReportsDialog(QString path_a, QWidget *parent) :
    QWidget(parent)
{
    path = path_a;
    lay = new QHBoxLayout(this);
    img_wid = new QLabel();
    img_wid->setFixedSize(640,480);
    if(!path.isEmpty()) {
        img_wid->setPixmap(QPixmap::fromImage(QImage(path).scaled(640,480)));
    }
    else    {
        img_wid->setText(tr("<font size=\"3\">NO IMAGE</font>"));
    }
   lay->addWidget(img_wid);

}
