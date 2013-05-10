#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QObject>
#include <QString>

#define ID_TYPE QString
class Symptom : public QObject
{
    Q_OBJECT

    ID_TYPE id;
    QString *description;
    QString *characteristics;
    QList<ID_TYPE> *linkedTo;
public:
    explicit Symptom(QObject *parent = 0);
    ~Symptom();

    QString getDescription();
    void setDescription(QString arg);

    QString getCharacteristics();
    void setCharacteristics(QString arg);

    QList<ID_TYPE> getLinkedTo();
    bool addLink(ID_TYPE arg);
    bool removeLink(ID_TYPE arg);

signals:

public slots:

};

#endif // SYMPTOM_H
