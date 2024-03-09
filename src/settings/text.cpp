#include "text.h"

#include <iostream>

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
    // data.insert(std::make_pair(Constants:, ""));
    // std::cout << data.size() << std::endl;
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
