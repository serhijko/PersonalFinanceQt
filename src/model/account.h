#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <list>

#include "icommon.h"
#include "currency.h"
#include "transaction.h"
#include "transfer.h"

class Account : public ICommon
{
    QString title;
    Currency *currency = nullptr;
    double startAmount;
    double amount;

public:
    Account() = default;
    Account(const QString &title, Currency *currency, double startAmount);
    ~Account() = default;

    QString getTitle() const;
    void setTitle(const QString &value);

    Currency *getCurrency() const;
    void setCurrency(Currency *value);

    double getStartAmount() const;
    void setStartAmount(double value);

    double getAmount() const;

    QTextStream &operator <<(QTextStream &stream) const override;
    QString toString() const override;
    bool equals(const ICommon *obj) const override;
    const QString &getValueForComboBox() const override;

    void setAmountFromTransactionsAndTransfers(std::list<Transaction*> transactions,
                                               std::list<Transfer*> transfers);
};

#endif // ACCOUNT_H
