#include "UI.h"


UI::UI(Restaurant** ptr)
{
    _ResPtr = ptr;
}

void UI::printMenu()
{
    int input;

    do{
        std::cout << "Project Name Place Holder\n" << "--------------------------\n" << "1. Show all Restaurants\n" << "2. Search by Prices\n" << "3. Search by Cuisine\n" << "4. Search by Rating\n" << "5. Give a Rating\n" << "6. Remove a Restaurant\n" << "7. Random\n" << "8. Exit Program\n";
        std::cin >> input;

        while(std::cin.fail() || input < 1 || input > 8)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
            std::cin >> input;
        }


        if(input == 1)
        {
            printAll();


        }
        else if(input == 2)
        {
            int lower, higher;
            std::cout << "1. $, 2. $$, 3. $$$, 4. $$$$\n" << "use the number lable to select the price range\n";

            std::cout << "Please give a lower price range: ";
            while(std::cin.fail() || lower < 1 || lower > 4) // lower has to be in and within range.
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> lower;
            }

            std::cout << "Please give a higher price range: ";
            while(std::cin.fail() || higher < lower || higher > 4) // higher has to be an int, has to be greater than or equal to lower, has to be with in highest range.
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> higher;
            }


            printByPrice(lower, higher);

            
        }
        else if(input == 3)
        {}
    }
}

void UI::printAll()
{}

void UI::printByPrice(int lower, int higher)
{}

void UI::printByCuisine(int choice)
{}

void UI::printByRating()
{}

void UI::printRandom()
{}

void UI::giveRating()
{}

void UI::removeRestaurant()
{}

int UI::intInputCheck()
{
    int input;
    std::cin >> input;

        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
            std::cin >> input;
        }

    return input;
}