#ifndef DISPLAYREPORTSDIALOG_H
#define DISPLAYREPORTSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QImage>
#include <QPixmap>

class DisplayReportsDialog : public QWidget
{
    Q_OBJECT
    QString path;
    QLabel *img_wid;
    QHBoxLayout *lay;

public:
    explicit DisplayReportsDialog(QString path_a, QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DISPLAYREPORTSDIALOG_H
