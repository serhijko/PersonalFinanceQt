#include "filter.h"

Filter::Filter()
    : Filter(Step::MONTH)
{
}

Filter::Filter(uint8_t step)
{
    this->step = step;
}

uint8_t Filter::getStep() const
{
    return step;
}

QDate Filter::getFrom() const
{
    return from;
}

QDate Filter::getTo() const
{
    return to;
}

void Filter::setFromTo(const QDate &value)
{
    switch (step) {
    case Step::DAY:
        from.setDate(value.year(), value.month(), value.day());
        to.setDate(value.year(), value.month(), value.day() + 1);
        break;
    case Step::MONTH:
        from.setDate(value.year(), value.month(), 1);
        to.setDate(value.year(), value.month() + 1, 1);
        break;
    case Step::YEAR:
        from.setDate(value.year(), 1, 1);
        to.setDate(value.year() + 1, 1, 1);
        break;
    }
    to = value;
}

void Filter::next()
{
    offset(1);
}

void Filter::prev()
{
    offset(-1);
}

void Filter::nextPeriod()
{
    ++step;
    if (step > Step::YEAR) step = Step::DAY;
    setFromTo(QDate::currentDate());
}

bool Filter::check(const QDate &date) const
{
    return date >= from && date < to;
}

void Filter::offset(bool i)
{
    QDate calendar(from);
    switch (step) {
    case Step::DAY:
        calendar.addDays(i);
        break;
    case Step::MONTH:
        calendar.addMonths(i);
        break;
    case Step::YEAR:
        calendar.addYears(i);
        break;
    }
    setFromTo(calendar);
}
