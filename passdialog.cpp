#include "passdialog.h"

PassDialog::PassDialog(QString user_a, QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    setWindowTitle(tr("Enter password"));
    curr_user=user_a;
    h_layout=new QHBoxLayout(this);

    pass_l=new QLabel("Password");
    pass_e=new QLineEdit();
    pass_e->setEchoMode(QLineEdit::Password);
    done_button=new QPushButton("Log In");

    h_layout->addWidget(pass_l);
    h_layout->addWidget(pass_e);
    h_layout->addWidget(done_button);
    connect(done_button,SIGNAL(clicked()),this,SLOT(button_clicked()));
}

void PassDialog::button_clicked()
{
    PassMan *pass_man=new PassMan("/home/user/.config/.sehatpass");
    pass_man->loadPassList();
    //qDebug()<<"Curr user=" << curr_user;
    if(pass_man->checkPass(curr_user,pass_e->text()))
       accept();
    else
       reject();
}
