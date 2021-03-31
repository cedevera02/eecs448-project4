#include "Executive.h"
#include <iostream>
#include <stdio.h>



Executive::Executive()
{
    m_restVector = new std::vector<Restaurant>;
    m_UI = UI(m_restVector);
    m_loginStatus = false;
}


Executive::~Executive()
{
    m_restVector->clear();
    delete m_restVector;
}

void Executive::run()
{
    /*
    I assume we'll ask them if they are new or returning, if new ask for a name, if return ask to login
    and record the userName since it is the file name that we need to open
    if(newUser) {
        readIn(STD_FILE_NAME);
    } else {
        readIn("userName.txt")
    }

    while(menuChoice != EXIT_CODE)
    {
        I assume we call UI menu print here, I think it should return the choice so we can use it

        switch statement to catch all cases and call proper UI methods
    }
    */
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
            for(int i=0; i < _cuisineVec.size(); i++)
            {
                std::cout << i << ". " << _cuisineVec[i] << "\n";
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

            printByCuisine(_cuisineVec[choice]);


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
            if(m_loginStatus)
            {

            }
            else
            {
                std::cout << "You are not logged in. Please restart and lopgin to use this feature.\n";
            }
        }
        else if(input == 6) // Remove.
        {
            if(m_loginStatus)
            {

            }
            else
            {
                std::cout << "You are not logged in. Please restart and lopgin to use this feature.\n";
            }
        }
        else if(input == 7) // Random.
        {
            printRandom();


        }
        else //exit.
        {
            running = false;
        }
}

bool Executive::readIn(std::string fileToParse)
{
    m_file.open(fileToParse);
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

void Executive::writeOut(const char* fileToWrite)
{
    if(!m_isNewUser)
    {
        remove(fileToWrite);
    }

    m_file.open(fileToWrite);
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
        for(int j=0;  j < m_cuisineVector.size(); j++)
        {
            if(m_cuisineVector[i] == m_cuisineVector[j])
            {
                repeat = true;
                break;
            }
        }
        if(!repeat)
        {
            m_cuisineVector[i] == _resVector[i].getCusine();
        }
    }
}