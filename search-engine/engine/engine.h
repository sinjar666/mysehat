#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QMultiHash>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include "indexitem.h"


class Engine : public QObject
{
    Q_OBJECT
public:
    typedef enum    {
        APPOINTMENT_F=0,
        SYMPTOM_F = 1<<0,
        ALLERGEN_F = 1<<1,
        DRUG_F= 1<<2,
        INVESTIGATION_F=1<<3,
        SURGERY_F = 1 << 4,
        FAMILYHIST_F = 1 << 5,
        MISC_F = 1 << 6
    } Filters;
    explicit Engine(QString path_a,QObject *parent = 0);
    void loadIndex();
    void saveIndex();
    void createEmptyIndex();
    void addEntry(QString keyword,IndexItem item);
    QList<IndexItem> getEntry(QString keyword);
    QList<IndexItem> getSubstringMatch(QString keyword);
    QList<QString> getKeys(IndexItem val);
    bool remove(QString key,IndexItem val);
    bool remove(QString key);

    void setFilter(Filters arg,bool status=true);
    quint8 getFilters();

private:
    QMultiHash<QString,IndexItem> index;

    QFile *file;
    QString *path;
    quint8 filterby;

signals:

public slots:

};

#endif // ENGINE_H
