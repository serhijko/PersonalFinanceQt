#include "transaction.h"
#include "modelexception.h"

Transaction::Transaction(Account *account, Article *article, double amount, const QString &notice,
                         const QDate &date)
{
    if (account == nullptr) throw new ModelException(ModelException::Code::ACCOUNT_EMPTY);
    if (article == nullptr) throw new ModelException(ModelException::Code::ARTICLE_EMPTY);
    this->account = account;
    this->article = article;
    this->amount = amount;
    this->notice = notice;
    this->date = date;
}

Transaction::Transaction(Account *account, Article *article, double amount, const QString &notice)
    : Transaction(account, article, amount, notice, QDate::currentDate())
{
}

Transaction::Transaction(Account *account, Article *article, double amount, const QDate &date)
    : Transaction(account, article, amount, "", date)
{
}

Account *Transaction::getAccount() const
{
    return account;
}

void Transaction::setAccount(Account *account)
{
    this->account = account;
}

Article *Transaction::getArticle() const
{
    return article;
}

void Transaction::setArticle(Article *article)
{
    this->article = article;
}

double Transaction::getAmount() const
{
    return amount;
}

void Transaction::setAmount(double amount)
{
    this->amount = amount;
}

QString Transaction::getNotice() const
{
    return notice;
}

void Transaction::setNotice(const QString &amount)
{
    this->notice = amount;
}

QDate Transaction::getDate() const
{
    return date;
}

void Transaction::setDate(const QDate &date)
{
    this->date = date;
}

QTextStream &Transaction::operator <<(QTextStream &stream) const
{
    return stream << "Transaction(account=[" << account << "], article=[" << article
                  << "], amount=[" << amount << "], notice=" << notice << ", date=" << date.toString() << ')';
}

QString Transaction::toString() const
{
    return "Transaction(account=[" + account->toString() + "], article=[" + article->toString()
            + "], amount=[" + amount + "], notice=" + notice + ", date=" + date.toString() + ')';
}

bool Transaction::equals(const ICommon *obj) const
{
    if (this == obj) {
        return true;
    }
    return false;
}

const QString &Transaction::getValueForComboBox() const
{
    return this->notice;
}
