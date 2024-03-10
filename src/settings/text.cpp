#include "text.h"

//#include <iostream>

std::unordered_map<unsigned, const char*> Text::data;

void Text::init()
{
    data.insert(std::make_pair(Constants::PROGRAM_NAME, "Personal Finance"));

    data.insert(std::make_pair(Constants::JANUARY, "January"));
    data.insert(std::make_pair(Constants::FEBRUARY, "February"));
    data.insert(std::make_pair(Constants::MARCH, "March"));
    data.insert(std::make_pair(Constants::APRIL, "April"));
    data.insert(std::make_pair(Constants::MAY, "May"));
    data.insert(std::make_pair(Constants::JUNE, "June"));
    data.insert(std::make_pair(Constants::JULY, "July"));
    data.insert(std::make_pair(Constants::AUGUST, "August"));
    data.insert(std::make_pair(Constants::SEPTEMBER, "September"));
    data.insert(std::make_pair(Constants::OCTOBER, "October"));
    data.insert(std::make_pair(Constants::NOVEMBER, "November"));
    data.insert(std::make_pair(Constants::DECEMBER, "December"));

    data.insert(std::make_pair(Constants::MENU_FILE, "File"));
    data.insert(std::make_pair(Constants::MENU_EDIT, "Edit"));
    data.insert(std::make_pair(Constants::MENU_VIEW, "View"));
    data.insert(std::make_pair(Constants::MENU_HELP, "Help"));

    data.insert(std::make_pair(Constants::ERROR_TITLE_EMPTY, "You have not entered a title!"));
    data.insert(std::make_pair(Constants::ERROR_IS_EXIST, "Such a record already exists!"));
    data.insert(std::make_pair(Constants::ERROR_DATE_FORMAT, "Invalid date format!"));
    data.insert(std::make_pair(Constants::ERROR_CODE_EMPTY, "You haven't specified the currency code!"));
    data.insert(std::make_pair(Constants::ERROR_CURRENCY_EMPTY, "You haven't selected a currency!"));
    data.insert(std::make_pair(Constants::ERROR_ARTICLE_EMPTY, "You haven't selected an article!"));
    data.insert(std::make_pair(Constants::ERROR_ACCOUNT_EMPTY, "You haven't selected an account!"));
    data.insert(std::make_pair(Constants::ERROR_RATE_INCORRECT, "Invalid exchange rate value!"));
    data.insert(std::make_pair(Constants::ERROR_AMOUNT_FORMAT, "Incorrect amount format!"));
    data.insert(std::make_pair(Constants::ERROR_NO_BASE_CURRENCY,
                               "A base currency is required! "
                               "First set this parameter for another currency, "
                               "then it will be removed for this one automatically."));
    data.insert(std::make_pair(Constants::ERROR_UNKNOWN_EXCEPTION, "It's unknown model exception..."));

    // data.insert(std::make_pair(Constants:, ""));

}

const char* Text::get(const unsigned key)
{
    auto pairFound = data.find(key);
    if (pairFound != data.end())
        return pairFound->second;
    else
        return "Not found!";
}

const char** Text::getMonths()
{
    const char** months = new const char*[12] {
            get(Constants::JANUARY),
            get(Constants::FEBRUARY),
            get(Constants::MARCH),
            get(Constants::APRIL),
            get(Constants::MAY),
            get(Constants::JUNE),
            get(Constants::JULY),
            get(Constants::AUGUST),
            get(Constants::SEPTEMBER),
            get(Constants::OCTOBER),
            get(Constants::NOVEMBER),
            get(Constants::DECEMBER)
    };

    return months;
}
