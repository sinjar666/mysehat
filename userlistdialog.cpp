#include "userlistdialog.h"

UserListDialog::UserListDialog(QDir *pathdir_a,QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("Select a user"));
    pathdir=pathdir_a;
    //qDebug()<<pathdir->absolutePath();
    setWindowTitle(tr("User List"));
    setModal(true);
    vlayout = new QVBoxLayout(this);
    mesg = new QLabel(tr("Tap to choose user"));
    list_users = new QListWidget();
    Config *config_users=new Config(pathdir->absolutePath()+"/");
    QStringList user_list;
    user_list=config_users->userlist();
    //qDebug()<<user_list;

        list_users->addItems(user_list);
        vlayout->addWidget(list_users);
        connect(list_users,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onUserClick(QListWidgetItem*)));

}

void UserListDialog::onUserClick(QListWidgetItem *item)
{
    pathdir->cd(item->text());
    emit catchcurruser(item->text());
    accept();
}
