#include "UI.h"



UI::UI(std::vector<Restaurant> vec)
{
    _resVector = vec;

    bool repeat = false;
    for(int i=0; i < _resVector.size(); i++) // fills in the cuisine vector, checks to make sure doesn't repeat a cuisine.
    {
        for(int j=0;  j < _cuisineVec.size(); j++)
        {
            if(_cuisineVec[i] == _cuisineVec[j])
            {
                repeat = true;
                break;
            }
        }
        if(!repeat)
        {
            _cuisineVec[i] == _resVector[i].getCusine();
        }
    }
       
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
            for(i=0; i < )
            std::cout << "Please Select a cuisine: ";
            std::cin >> choice;
            while(std::cin.fail() || choice < 1 || choice > 24)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> choice;
            }
            std::string temp;

            printByCuisine(temp);


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
    for(int i=0; i < _resVector.size(); i++)
    {
        std::cout << _resVector[i].getName() << "  " << _resVector[i].getCusine() << "  " <<_resVector[i].getPrice() << "  Rating: " << _resVector[i].getRating() << "  Personal Rating: " << _resVector[i].getPRating() << "\n";
    }
}

void UI::printByPrice(int lower, int higher)
{
    bool haveRes = false; // to have a different cout when there are no Restaurtants that fit the category.
    for(int i=0; i < _resVector.size(); i++)
    {
        if(_resVector[i].getPrice() > lower && _resVector[i].getPrice() < higher)
        {
            haveRes = true;
            std::cout << _resVector[i].getName() << "  " << _resVector[i].getCusine() << "  " <<_resVector[i].getPrice() << "  Rating: " << _resVector[i].getRating() << "  Personal Rating: " << _resVector[i].getPRating() << "\n";
        }

    }

    if(haveRes == false)
    {
        std::cout << "No restaurants fit that criteria.\n";
    }
}

void UI::printByCuisine(std::string choice)
{
    bool haveRes = false; // to have a different cout when there are no Restaurtants that fit the category.
    for(int i=0; i < _resVector.size(); i++)
    {
        if(_resVector[i].getCusine() == 
        {
            haveRes = true;
            std::cout << _resVector[i].getName() << "  " << _resVector[i].getCusine() << "  " <<_resVector[i].getPrice() << "  Rating: " << _resVector[i].getRating() << "  Personal Rating: " << _resVector[i].getPRating() << "\n";
        }

    }

    if(haveRes == false)
    {
        std::cout << "No restaurants fit that criteria.\n";
    }
}

void UI::printByRating(int type)
{}

void UI::printRandom()
{}

void UI::giveRating()
{}

void UI::removeRestaurant()
{}
