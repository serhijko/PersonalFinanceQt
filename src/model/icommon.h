#ifndef ICOMMON_H
#define ICOMMON_H

#include <QString>
#include <QTextStream>

class ICommon
{
protected:
    ICommon() = default;
public:
    virtual ~ICommon() = default;

//    virtual void postAdd() = 0;
//    virtual void postEdit() = 0;
//    virtual void postRemove() = 0;

    virtual QTextStream &operator <<(QTextStream &stream) const = 0;
    virtual QString toString() const = 0;
    virtual bool equals(const ICommon* obj) const = 0;
    virtual const QString& getValueForComboBox() const = 0;
};

#endif // ICOMMON_H
