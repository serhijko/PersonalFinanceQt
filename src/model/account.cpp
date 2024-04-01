#include "account.h"
#include "modelexception.h"

Account::Account(const QString &title, Currency *currency, double startAmount)
{
    if (title.length() == 0) throw new ModelException(ModelException::Code::TITLE_EMPTY);
    if (currency == nullptr) throw new ModelException(ModelException::Code::CURRENCY_EMPTY);
    this->title = title;
    this->currency = currency;
    this->startAmount = startAmount;
}

QString Account::getTitle() const
{
    return this->title;
}

void Account::setTitle(const QString &title)
{
    this->title = title;
}

Currency *Account::getCurrency() const
{
    return currency;
}

void Account::setCurrency(Currency *currency)
{
    this->currency = currency;
}

double Account::getStartAmount() const
{
    return startAmount;
}

void Account::setStartAmount(double startAmount)
{
    this->startAmount = startAmount;
}

double Account::getAmount() const
{
    return amount;
}

QTextStream &Account::operator <<(QTextStream &stream) const
{
    return stream << "Account(title=" << title << ", currency=[" << currency << "], startAmount="
                  << startAmount << ", amount=" << amount + ')';
}

QString Account::toString() const
{
    return "Account(title=" + title + ", currency=[" + currency->toString() + "], startAmount="
            + startAmount + ", amount=" + amount + ')';
}

bool Account::equals(const ICommon *obj) const
{
    if (this == obj) {
        return true;
    }
    if (obj == nullptr) {
        return false;
    }
    const Account *other = dynamic_cast<const Account*>(obj);
    if (other == nullptr) {
        return false;
    }
    if (this->title != other->title) {
        return false;
    }
    return true;
}

const QString &Account::getValueForComboBox() const
{
    return this->title;
}

void Account::setAmountFromTransactionsAndTransfers(std::list<Transaction *> transactions,
                                                    std::list<Transfer *> transfers)
{
    amount = startAmount;
    for (Transaction *transaction : transactions) {
        if (transaction->getAccount()->equals(this)) {
            amount += transaction->getAmount();
        }
    }
    for (Transfer *transfer : transfers) {
        if (transfer->getFromAccount()->equals(this)) {
            amount -= transfer->getFromAmount();
        }
        if (transfer->getToAccount()->equals(this)) {
            amount += transfer->getToAmount();
        }
    }
}
