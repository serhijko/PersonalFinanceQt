#ifndef CURRENCY_H
#define CURRENCY_H

#include "icommon.h"

class Currency : public ICommon
{
    QString title;
    QString code;
    double rate;
    bool isOn;
    bool isBase;

public:
    Currency() = default;
    Currency(const QString &title, const QString &code, double rate, bool isOn, bool isBase);
    ~Currency() = default;

    QString getTitle() const;
    void setTitle(const QString &title);

    QString getCode() const;
    void setCode(const QString &title);

    double getRate() const;
    void setRate(double rate);

    bool getIsOn() const;
    void setIsOn(bool isOn);

    bool getIsBase() const;
    void setIsBase(bool isBase);

    QTextStream &operator <<(QTextStream &stream) const override;
    QString toString() const override;
    bool equals(const ICommon* obj) const override;
    const QString &getValueForComboBox() const override;

    double getRateByCurrency(const Currency &currency) const;
};

#endif // CURRENCY_H
