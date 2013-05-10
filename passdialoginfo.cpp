#include "passdialoginfo.h"

PassDialogInfo::PassDialogInfo(bool status, QWidget *parent) :
    QDialog(parent)
{
    h_layout=new QHBoxLayout(this);
    ok_button=new QPushButton("OK");
    if(status)
    {
        t_message=new QLabel(tr("You have been successfully logged in"));
        h_layout->addWidget(t_message);
    }
    else
    {
        f_message=new QLabel(tr("The password is wrong..Try again"));
        h_layout->addWidget(f_message);
    }
    h_layout->addWidget(ok_button);
    connect(ok_button,SIGNAL(clicked()),this,SLOT(accept()));
}
