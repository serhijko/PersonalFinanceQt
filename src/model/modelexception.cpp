#include "modelexception.h"
#include "../settings/text.h"

const char *ModelException::what() const throw()
{
    switch (code) {
    case TITLE_EMPTY:
        return Text::get(Text::ERROR_TITLE_EMPTY);
    case IS_EXIST:
        return Text::get(Text::ERROR_IS_EXIST);
    case DATE_FORMAT:
        return Text::get(Text::ERROR_DATE_FORMAT);
    case CODE_EMPTY:
        return Text::get(Text::ERROR_CODE_EMPTY);
    case CURRENCY_EMPTY:
        return Text::get(Text::ERROR_CURRENCY_EMPTY);
    case ARTICLE_EMPTY:
        return Text::get(Text::ERROR_ARTICLE_EMPTY);
    case ACCOUNT_EMPTY:
        return Text::get(Text::ERROR_ACCOUNT_EMPTY);
    case RATE_INCORRECT:
        return Text::get(Text::ERROR_RATE_INCORRECT);
    case AMOUNT_FORMAT:
        return Text::get(Text::ERROR_AMOUNT_FORMAT);
    case NO_BASE_CURRENCY:
        return Text::get(Text::ERROR_NO_BASE_CURRENCY);
    default:
        return Text::get(Text::ERROR_UNKNOWN_EXCEPTION);
    }
}
