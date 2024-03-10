#ifndef ICOMMON_H
#define ICOMMON_H


class ICommon
{
protected:
    ICommon() = default;
public:
    virtual ~ICommon() = default;

    virtual void postAdd() = 0;
    virtual void postEdit() = 0;
    virtual void postRemove() = 0;

    virtual const char* getValueForComboBox() = 0;
};

#endif // ICOMMON_H
