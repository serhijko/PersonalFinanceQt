#include "transfer.h"
#include "modelexception.h"

Transfer::Transfer(Account *fromAccount, Account *toAccount, double fromAmount, double toAmount,
                 const QString &notice, const QDate &date)
{
    if (fromAccount == nullptr) throw new ModelException(ModelException::Code::ACCOUNT_EMPTY);
    if (toAccount == nullptr) throw new ModelException(ModelException::Code::ACCOUNT_EMPTY);
    if (fromAmount < 0 || toAmount < 0) throw new ModelException(ModelException::Code::AMOUNT_FORMAT);
    this->fromAccount = fromAccount;
    this->toAccount = toAccount;
    this->fromAmount = fromAmount;
    this->toAmount = toAmount;
    this->notice = notice;
    this->date = date;
}

Transfer::Transfer(Account *fromAccount, Account *toAccount, double fromAmount, double toAmount,
                 const QString &notice)
    : Transfer{fromAccount, toAccount, fromAmount, toAmount, notice, QDate::currentDate()}
{
}

Transfer::Transfer(Account *fromAccount, Account *toAccount, double fromAmount, double toAmount,
                   const QDate &date)
    : Transfer(fromAccount, toAccount, fromAmount, toAmount, "", date)
{
}

Account *Transfer::getFromAccount() const
{
    return fromAccount;
}

void Transfer::setFromAccount(Account *fromAccount)
{
    this->fromAccount = fromAccount;
}

Account *Transfer::getToAccount() const
{
    return toAccount;
}

void Transfer::setToAccount(Account *toAccount)
{
    this->toAccount = toAccount;
}

double Transfer::getFromAmount() const
{
    return fromAmount;
}

void Transfer::setFromAmount(double fromAmount)
{
    this->fromAmount = fromAmount;
}

double Transfer::getToAmount() const
{
    return toAmount;
}

void Transfer::setToAmount(double toAmount)
{
    this->toAmount = toAmount;
}

QString Transfer::getNotice() const
{
    return notice;
}

void Transfer::setNotice(const QString &notice)
{
    this->notice = notice;
}

QDate Transfer::getDate() const
{
    return date;
}

void Transfer::setDate(const QDate &date)
{
    this->date = date;
}

QTextStream &Transfer::operator <<(QTextStream &stream) const
{
    return stream << "Transfer(fromAccount=[" << fromAccount << "], toAccount=[" << toAccount
                  << "], fromAmount=[" << fromAmount << "], toAmount=[" << toAmount
                  << "], notice=" << notice << ", date=" << date.toString() << ')';
}

QString Transfer::toString() const
{
    return "Transfer(fromAccount=[" + fromAccount->toString() + "], toAccount=[" + toAccount->toString()
            + "], fromAmount=[" + fromAmount + "], toAmount=[" + toAmount
            + "], notice=" + notice + ", date=" + date.toString() + ')';
}

bool Transfer::equals(const ICommon *obj) const
{
    if (this == obj) {
        return true;
    }
    return false;
}

const QString &Transfer::getValueForComboBox() const
{
    return this->notice;
}
