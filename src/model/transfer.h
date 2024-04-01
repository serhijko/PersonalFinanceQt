#ifndef TRANSER_H
#define TRANSER_H

#include <QDate>

#include "icommon.h"
#include "account.h"

class Transfer : public ICommon
{
    Account *fromAccount = nullptr;
    Account *toAccount = nullptr;
    double fromAmount;
    double toAmount;
    QString notice;
    QDate date;

public:
    Transfer() = default;
    Transfer(Account *fromAccount, Account *toAccount, double fromAmount, double toAmount,
            const QString &notice, const QDate &date);
    Transfer(Account *fromAccount, Account *toAccount, double fromAmount, double toAmount,
            const QString &notice = "");
    Transfer(Account *fromAccount, Account *toAccount, double fromAmount, double toAmount, const QDate &date);
    ~Transfer() = default;

    Account *getFromAccount() const;
    void setFromAccount(Account *value);

    Account *getToAccount() const;
    void setToAccount(Account *value);

    double getFromAmount() const;
    void setFromAmount(double value);

    double getToAmount() const;
    void setToAmount(double value);

    QString getNotice() const;
    void setNotice(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    QTextStream &operator <<(QTextStream &stream) const;
    QString toString() const;
    bool equals(const ICommon *obj) const;
    const QString &getValueForComboBox() const;
};

#endif // TRANSER_H
