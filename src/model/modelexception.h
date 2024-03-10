#ifndef MODELEXCEPTION_H
#define MODELEXCEPTION_H

#include <exception>

class ModelException : public std::exception
{
    int code = 0;
public:
    ModelException(int code) : code(code) {}

    enum Code
    {
        TITLE_EMPTY = 1,
        IS_EXIST,
        DATE_FORMAT,
        CODE_EMPTY,
        CURRENCY_EMPTY,
        ARTICLE_EMPTY,
        ACCOUNT_EMPTY,
        RATE_INCORRECT,
        AMOUNT_FORMAT,
        NO_BASE_CURRENCY
    };

    virtual const char* what() const throw() override;
};

#endif // MODELEXCEPTION_H
