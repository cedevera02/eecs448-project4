#include "Executive.h"
#include <iostream>
#include <stdio.h>
#include <unordered_set>



Executive::Executive()
{
    m_restVector = new std::vector<Restaurant>;
    //m_UI = UI(m_restVector);
    m_isReturning = false;
    m_menuChoice = 0;
    m_Account = Account();
}


Executive::~Executive()
{
    m_restVector->clear();
    delete m_restVector;
}

void Executive::run()
{

    std::cout << "Are you a new (0) or returning user (1) ?: ";
    std::cin >> m_isReturning;

    while (std::cin.fail() || m_isReturning < 0 || m_isReturning > 1) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
        std::cin >> m_isReturning;
    }

    std::string tempName;
    if(!m_isReturning) {
        readIn(STD_FILE_NAME);
        std::cout << "Would you like to be a guest (0) or create (1) an account?: ";
        std::cin >> m_isReturning;

        while (std::cin.fail() || m_isReturning < 0 || m_isReturning > 1) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
            std::cin >> m_isReturning;
        }

        

        if(!m_isReturning) {
            m_Account.setName("GUEST");
        } else {
            std::cout << "Create a username: ";
            std::cin >> tempName;
            m_Account.setName("a" + tempName); //add a to the front to ensure that they can't enter blank name
        }
    } else {

        std::cout << "Welcome back! Please enter your username (case-sensitive): ";
        std::cin >> tempName;
        tempName = "a" + tempName; //add a to keep with username creation convention

        while(!m_Account.Login(tempName)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Username not found. Either restart (ctrl-c) and create an account or try again: ";
            std::cin >> tempName;
        }

        readIn(tempName);
    }
    m_UI = UI(m_restVector);
    fillCuisineVector();

    while(m_menuChoice != EXIT_CODE)
    {
        m_menuChoice = m_UI.printMenu();

        if(m_menuChoice == SHOW_ALL_CODE)
        {
            m_UI.printAll();
        }
        else if(m_menuChoice == SEARCH_PRICE_CODE)
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

            m_UI.printByPrice(lower, higher);


        }
        else if(m_menuChoice == SEARCH_TYPE_CODE)
        {
            int choice;
            for(int i=0; i < m_cuisineVector.size(); i++)
            {
                std::cout << i << ". " << m_cuisineVector[i] << "\n";
            }
            std::cout << "Please Select a cuisine: ";
            std::cin >> choice;
            while(std::cin.fail() || choice < 1 || choice > 24)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> choice;
            }

            m_UI.printByCuisine(m_cuisineVector[choice]);


        }
        else if(m_menuChoice == SEARCH_RATING_CODE) // Search By Ratings.
        {
            int typeChoice;
            double ratingChoice;
            std::cout << "Would you like to search by\n1. Personal Ratings\n2. Public Ratings\n";
            std::cin >> typeChoice;
            while(std::cin.fail() || typeChoice < 1 || typeChoice > 2)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> typeChoice;
            }

            std::cout << "Enter a rating you would like to search for (1-5): ";
            std::cin >> ratingChoice;
            while(std::cin.fail() || typeChoice < 1 || typeChoice > 5)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                std::cin >> typeChoice;
            }
            m_UI.printByRating(typeChoice, ratingChoice);


        }
        else if(m_menuChoice == GIVE_RATING_CODE) // Give a rating.
        {
            if(m_isReturning)
            {
                std::string restChoice;
                std::unordered_set <std::string> checkerSet;
                int aRatingToAdd;

                std::cout << "Select a restaurant from the list below to add a rating to: \n";
                for(int i = 0; i < m_restVector->size(); i++) {
                    std::cout << m_restVector->at(i).getName() << ", ";
                    checkerSet.insert(m_restVector->at(i).getName());
                    if(i != 0 && i % 4 == 0) {
                        std::cout << "\n";
                    }
                }
                std::cout << "Entry: ";
                std::cin >> restChoice;

                while(std::cin.fail() || (checkerSet.find(restChoice) == checkerSet.end())) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                    std::cin >> restChoice;
                }

                std::cout << "Enter the rating that you would like to add: ";
                std::cin >> aRatingToAdd;

                while(std::cin.fail() || aRatingToAdd < 1 || aRatingToAdd > 5) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                    std::cin >> aRatingToAdd;
                }

                m_UI.giveRating(restChoice, aRatingToAdd);

            }
            else
            {
                std::cout << "You are not logged in. Please restart and login to use this feature.\n";
            }
        }
        else if(m_menuChoice == REMOVE_REST_CODE) // Remove.
        {
            

            if(m_isReturning)
            {
                std::string restChoice;


                std::cout << "Enter the name of the restaurant that you would like to remove from the list: ";
                std::cin >> restChoice;

                while(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
                    std::cin >> restChoice;
                }

                m_UI.removeRestaurant(restChoice);

            }
            else
            {
                std::cout << "You are not logged in. Please restart and login to use this feature.\n";
            }
        }
        else if(m_menuChoice == RANDOM_CODE) // Random.
        {
            m_UI.printRandom();
        }
    }

    if(m_isReturning) {
        writeOut(tempName);
        std::cout << "Data saved!\n";
    }

    std::cout << "\n(∗ ･‿･)ﾉ゛Goodbye!\n";
}

bool Executive::readIn(std::string fileToParse)
{
    m_file.open(fileToParse + ".txt");
    if(m_file.is_open()) 
    {
        while(m_file >> m_tempRestName >> m_tempRestType >> m_tempPricing >> m_tempRating) 
        {
            Restaurant temp = Restaurant(m_tempRestName);
            temp.setCuisine(m_tempRestType);
            temp.setPrice(m_tempPricing);
            temp.setPRating(m_tempRating);
            m_restVector->push_back(temp);
        }
        m_file.close();
        return true;
    } 
    else 
    {
        std::cout << "Couldn't open read " << fileToParse << " file!\n";
        return false;
    }
}

void Executive::writeOut(std::string fileToWrite)
{
    m_file.open(fileToWrite + ".txt", std::ios::out | std::ios::trunc); // I believe the second arg will clear the file
    if(m_file.is_open())
    {
        for(int i = 0; i< m_restVector->size(); i++) {
            m_file << m_restVector->at(i).getName() << " " << m_restVector->at(i).getCusine() 
            << " " << m_restVector->at(i).getPrice() << " " << m_restVector->at(i).getRating() << " " << m_restVector->at(i).getPRating() << std::endl;
        }
    }
    else
    {
        std::cout << "Couldn't open write " << fileToWrite << " file!\n";
    }
}

void Executive::fillCuisineVector()
{
    bool repeat = false;
    for(int i=0; i < m_restVector->size(); i++) // fills in the cuisine vector, checks to make sure doesn't repeat a cuisine.
    {
        for(int j=0;  j < m_cuisineVector.size(); j++) //probably rewrite this later to use a hash-table so we don't need nested for loops
        {
            if(m_cuisineVector[i] == m_cuisineVector[j])
            {
                repeat = true;
                break;
            }
        }
        if(!repeat)
        {
            m_cuisineVector[i] == m_restVector->at(i).getCusine();
        }
    }
}