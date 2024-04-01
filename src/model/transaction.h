#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>

#include "icommon.h"
#include "account.h"
#include "article.h"

class Transaction : public ICommon
{
    Account *account = nullptr;
    Article *article = nullptr;
    double amount;
    QString notice;
    QDate date;

public:
    Transaction() = default;
    Transaction(Account *account, Article *article, double amount, const QString &notice, const QDate &date);
    Transaction(Account *account, Article *article, double amount, const QString &notice = "");
    Transaction(Account *account, Article *article, double amount, const QDate &date);
    ~Transaction() = default;

    Account *getAccount() const;
    void setAccount(Account *value);

    Article *getArticle() const;
    void setArticle(Article *value);

    double getAmount() const;
    void setAmount(double value);

    QString getNotice() const;
    void setNotice(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    QTextStream &operator <<(QTextStream &stream) const;
    QString toString() const;
    bool equals(const ICommon *obj) const;
    const QString &getValueForComboBox() const;
};

#endif // TRANSACTION_H
