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
