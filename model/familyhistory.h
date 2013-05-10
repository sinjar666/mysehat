#ifndef FAMILYHISTORY_H
#define FAMILYHISTORY_H

#include <QObject>
#include <QString>

#define ID_TYPE QString
class FamilyHistory : public QObject
{
    Q_OBJECT

    ID_TYPE *id;
    QString *name; //Name of disease
    quint8 members;
public:
    typedef enum    {
        MOTHER_T = 1 << 0,
        FATHER_T = 1 << 1,
        BROTHER_T = 1 << 2,
        SISTER_T = 1 << 3,
        GRANDFATHER_T = 1 << 4,
        GRANDMOTHER_T = 1 << 5
    } Members;
    explicit FamilyHistory(QObject *parent = 0);
    ~FamilyHistory();
    void setName(QString arg);
    QString getName();
    quint8 getMembers();
    void setMembers(quint8 arg);

    void addMember(Members arg);
    bool isMother();
    bool isFather();
    bool isBrother();
    bool isSister();
    bool isGrandfather();
    bool isGrandmother();
signals:

public slots:

};

#endif // FAMILYHISTORY_H
