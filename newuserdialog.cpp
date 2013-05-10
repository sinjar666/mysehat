#include "newuserdialog.h"

NewUserDialog::NewUserDialog(QDir *pathdir_a,QWidget *parent) :
    QDialog(parent)
{
    setModal(true);
    pathdir=pathdir_a;
    setWindowTitle(tr("Add New User"));
    glayout =new QGridLayout(this);
    newuser_l=new QLabel(tr("Name"));
    pass_l=new QLabel(tr("Password"));
    newuser_e=new QLineEdit();
    pass_e=new QLineEdit();
    pass_e->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    button=new QPushButton(tr("Add User"));

    glayout->addWidget(newuser_l,0,0);
    glayout->addWidget(newuser_e,0,1);
    glayout->addWidget(pass_l,1,0);
    glayout->addWidget(pass_e,1,1);
    glayout->addWidget(button,2,0);
    glayout->addWidget(new QLabel(),2,1);

    connect(button,SIGNAL(clicked()),this,SLOT(config_user()));
}

void NewUserDialog::config_user()
{
    if(newuser_e->text().isEmpty()||pass_e->text().isEmpty())   {
        QErrorMessage *mesg = new QErrorMessage(this);
        mesg->showMessage(tr("You should enter the username and password."));
        return;
    }
    Config *nuser=new Config(pathdir->absolutePath()+"/"); //configuring config.xml
    pathdir->mkdir(newuser_e->text());//making new user directory
    pathdir->cd(newuser_e->text());
    nuser->adduser(newuser_e->text());
    //qDebug() << pathdir->absolutePath();
    nuser->deleteLater();
    Engine *engine = new Engine(pathdir->absolutePath()+"/"); //creating empty index file for the user
    engine->createEmptyIndex();
    //qDebug("after create index");
    engine->deleteLater();
    nuser->deleteLater();

    PassMan *pass_man=new PassMan("/home/user/.config/.sehatpass");
    pass_man->loadPassList();
    pass_man->addPass(newuser_e->text(),pass_e->text());
    pass_man->savePassList();
    emit username(newuser_e->text());
    accept();
}
