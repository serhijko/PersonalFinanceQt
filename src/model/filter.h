#ifndef FILTER_H
#define FILTER_H

#include <QDate>

class Filter
{
    uint8_t step;
    QDate from;
    QDate to;

public:
    // Step Constants
    enum Step
    {
        DAY,
        MONTH,
        YEAR
    };

    Filter();
    Filter(uint8_t step);

    uint8_t getStep() const;

    QDate getFrom() const;

    QDate getTo() const;

    void setFromTo(const QDate &value);

    void next();
    void prev();

    void nextPeriod();

    bool check(const QDate &date) const;

private:
    void offset(bool i);
};

#endif // FILTER_H
