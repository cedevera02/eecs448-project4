#include "UI.h"


UI::UI(Restaurant** ptr)
{
    _ResPtr = ptr;
}

void UI::printMenu()
{
    int input;
    bool running = true;

    do{
        std::cout << "Project Name Place Holder\n--------------------------\n1. Show all Restaurants\n2. Search by Prices\n3. Search by Cuisine\n4. Search by Rating\n5. Give a Rating\n6. Remove a Restaurant\n7. Random\n8. Exit Program\n";
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
            std::cout << "1. $, 2. $$, 3. $$$\n(use the number lable to select the price range)\n";

            std::cout << "Please give a lower price range: ";
            std::cin >> lower;
            while(std::cin.fail() || lower < 1 || lower > 3) // lower has to be in and within range.
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> lower;
            }

            std::cout << "Please give a higher price range: ";
            std::cin >> higher;
            while(std::cin.fail() || higher < lower || higher > 3) // higher has to be an int, has to be greater than or equal to lower, has to be with in highest range.
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> higher;
            }

            printByPrice(lower, higher);


        }
        else if(input == 3)
        {
            int choice;
            //American,Asian,Asian_Fusion,Barbeque,Cajun,Chinese,Diner,Fast_Casual,Fast_Food,Greek,Hawaiian,Healthy,Italian,Mediterranean,Mexican,New_American,Pizza,Ramen,Sandwich,Seafood,Steak,Sushi,Tex_mex,Thai
            std::cout << "1. American\n2. Asian\n3. "; // NEED TO FINISH
            std::cout << "Please Select a cuisine: ";
            std::cin >> choice;
            while(std::cin.fail() || choice < 1 || choice > 24)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> choice;
            }
            printByCuisine(choice);


        }
        else if(input == 4) // Search By Ratings.
        {
            int choice;
            std::cout << "Would you like to search by\n1. Personal Ratings\n2. Public Ratings\n";
            std::cin >> choice;
            while(std::cin.fail() || choice < 1 || choice > 2)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> choice;
            }
            printByRating(choice);


        }
        else if(input == 5) // Give a rating.
        {

        }
        else if(input == 6) // Remove.
        {

        }
        else if(input == 7) // Random.
        {
            printRandom();


        }
        else //exit.
        {
            running = false;
        }

    }while(running);
}

void UI::printAll()
{
    for(int i=0; i < _gameSize; i++)
     {
         std::cout << _ResPtr[i]->getName() << " (" << _ResPtr[i]->getYear() << ") [" <<_ResPtr[i]->getGR() << ", " << _ResPtr[i]->getPR() << ", " << _ResPtr[i]->getMP() << ", " << _ResPtr[i]->getMT() << "] \n";
     }
}

void UI::printByPrice(int lower, int higher)
{}

void UI::printByCuisine(int choice)
{}

void UI::printByRating(int type)
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