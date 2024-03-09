#ifndef TEXT_H
#define TEXT_H

#include <string>
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
        MENU_HELP
    };

    static void init();
    static const char* get(const unsigned key);
    static const char** getMonths();
};

#endif // TEXT_H
