#ifndef TEXT_H
#define TEXT_H

#include <unordered_map>

class Text
{
private:
    static std::unordered_map<unsigned, const char*> data;

public:
    // Text Constants
    enum Constants
    {
        PROGRAM_NAME,

        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER,

        MENU_FILE,
        MENU_EDIT,
        MENU_VIEW,
        MENU_HELP,

        ERROR_TITLE_EMPTY,
        ERROR_IS_EXIST,
        ERROR_DATE_FORMAT,
        ERROR_CODE_EMPTY,
        ERROR_CURRENCY_EMPTY,
        ERROR_ARTICLE_EMPTY,
        ERROR_ACCOUNT_EMPTY,
        ERROR_RATE_INCORRECT,
        ERROR_AMOUNT_FORMAT,
        ERROR_NO_BASE_CURRENCY,
        ERROR_UNKNOWN_EXCEPTION,

    };

    static void init();
    static const char* get(const unsigned key);
    static const char** getMonths();
};

#endif // TEXT_H
