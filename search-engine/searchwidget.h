#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class SearchWidget : public QWidget
{
    Q_OBJECT
    QHBoxLayout *layout;
    QPushButton *searchButton,*filterButton;
    QLineEdit *key_e;
public:
    explicit SearchWidget(QWidget *parent = 0);
    QString getKey();


signals:
    void searchPressed();
    void filter();
public slots:
    void buttonPressed();
    void filterPressed();
};

#endif // SEARCHWIDGET_H
