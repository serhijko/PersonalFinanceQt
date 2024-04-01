#include "currency.h"
#include "modelexception.h"

Currency::Currency(const QString &title, const QString &code, double rate, bool isOn, bool isBase)
{
    if (title.length() == 0) throw new ModelException(ModelException::Code::TITLE_EMPTY);
    if (code.length() == 0) throw new ModelException(ModelException::Code::CODE_EMPTY);
    if (rate <= 0) throw new ModelException(ModelException::Code::RATE_INCORRECT);
    this->title = title;
    this->code = code;
    this->rate = rate;
    this->isOn = isOn;
    this->isBase = isBase;
}

QString Currency::getTitle() const
{
    return title;
}

void Currency::setTitle(const QString &title)
{
    this->title = title;
}

QString Currency::getCode() const
{
    return code;
}

void Currency::setCode(const QString &code)
{
    this->code = code;
}

double Currency::getRate() const
{
    return rate;
}

void Currency::setRate(double rate)
{
    this->rate = rate;
}

bool Currency::getIsOn() const
{
    return isOn;
}

void Currency::setIsOn(bool isOn)
{
    this->isOn = isOn;
}

bool Currency::getIsBase() const
{
    return isBase;
}

void Currency::setIsBase(bool isBase)
{
    this->isBase = isBase;
}

QTextStream &Currency::operator <<(QTextStream &stream) const
{
    return stream << "Currency(title=" << title << ", code=" << code << ", rate=" << rate << ", isOn="
                  << isOn << ", isBase=" << isBase + ')';
}

QString Currency::toString() const
{
    return "Currency(title=" + title + ", code=" + code + ", rate=" + rate + ", isOn="
            + isOn + ", isBase=" + isBase + ')';
}

bool Currency::equals(const ICommon *obj) const
{
    if (this == obj) {
        return true;
    }
    if (obj == nullptr) {
        return false;
    }
    const Currency* other = dynamic_cast<const Currency*>(obj);
    if (other == nullptr) {
        return false;
    }
    if (this->code != other->code) {
        return false;
    }
    return true;
}

const QString &Currency::getValueForComboBox() const
{
    return title;
}

double Currency::getRateByCurrency(const Currency &currency) const
{
    return this->rate / currency.rate;
}

