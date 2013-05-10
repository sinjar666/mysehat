#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QImage>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextBrowser>
#include <QScrollArea>

class AboutDialog : public QDialog
{
    Q_OBJECT
    QLabel *icon_l;
    QTextBrowser *text_v;
    QHBoxLayout *lay;
    QScrollArea *area;

public:
    explicit AboutDialog(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ABOUTDIALOG_H
