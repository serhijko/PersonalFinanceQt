#include <QCoreApplication>
#include <iostream>

#include "settings/text.h"

void init()
{
    Text::init();
    // TODO: Connect Roboto-Light TTF font
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    init();
    std::cout << Text::get(Text::Constants::PROGRAM_NAME) << std::endl;
    for (size_t monthCounter = 0, number_of_months = 12; monthCounter < number_of_months; ++monthCounter)
        std::cout << Text::getMonths()[monthCounter] << std::endl;

    return a.exec();
}
