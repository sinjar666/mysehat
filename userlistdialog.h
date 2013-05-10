#ifndef USERLISTDIALOG_H
#define USERLISTDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QDir>

#include "config/config.h"

class UserListDialog : public QDialog
{
    Q_OBJECT
    QLabel *mesg;
    QListWidget *list_users;
    QVBoxLayout *vlayout;
    QDir *pathdir;

public:
    explicit UserListDialog(QDir *pathdir_a,QWidget *parent = 0);

signals:
    void catchcurruser(QString user);

public slots:
    void onUserClick(QListWidgetItem *item);

};

#endif // USERLISTDIALOG_H
