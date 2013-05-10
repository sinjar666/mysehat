#include "searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent) :
    QWidget(parent)
{
    key_e = new QLineEdit();

    searchButton = new QPushButton();
    filterButton = new QPushButton("filter...");
    QImage temp(":/icons/Search.png");
    searchButton->setIcon(QIcon(QPixmap::fromImage(temp).scaled(20,20)));
    layout = new QHBoxLayout(this);
    layout->addWidget(key_e);
    layout->addWidget(filterButton);
    layout->addWidget(searchButton);
    connect(searchButton,SIGNAL(clicked()),this,SLOT(buttonPressed()));
    connect(key_e,SIGNAL(returnPressed()),this,SLOT(buttonPressed()));
    connect(filterButton,SIGNAL(clicked()),this,SLOT(filterPressed()));
}

void SearchWidget::buttonPressed()  {
    emit searchPressed();
}

QString SearchWidget::getKey()  {
    return key_e->text();
}

void SearchWidget::filterPressed()  {
    emit filter();
}
