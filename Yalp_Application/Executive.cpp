#include "Executive.h"
#include <iostream>
#include <stdio.h>
#include <unordered_set>


///EXECUTIVE CONSTRUCTOR
///
///This will initalize local objects and some local variables
Executive::Executive()
{
    m_restVector = new std::vector<Restaurant>;
    m_Choices = nullptr;
    m_isReturning = false;
    m_menuChoice = 0;
    m_Account = Account();
    readIn(STD_FILE_NAME); //just for testing
}

///EXECUTIVE DESTRUCTOR
///
///Clears out the objects in the heap allocated restaurant vector, deletes pointer
Executive::~Executive()
{
    m_restVector->clear();
    delete m_restVector;
}

///METHODS
///
///This is the main game loop, called in main as the access point to the program, handles logic after menu choice, file writes and reads, input check
void Executive::run()
{

    std::cout << "Are you a new (0) or returning user (1) ?: ";
    std::cin >> m_isReturning;

    while (std::cin.fail() || m_isReturning < 0 || m_isReturning > 1) {
        correctInvalid();
        std::cin >> m_isReturning;
    }

    QString tempName;
    if(!m_isReturning) {
        readIn(STD_FILE_NAME);
        std::cout << "Would you like to be a guest (0) or create (1) an account?: ";
        std::cin >> m_isReturning;

        while (std::cin.fail() || m_isReturning < 0 || m_isReturning > 1) {
            correctInvalid();
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
       // tempName = "a" + tempName; //add a to keep with username creation convention

        while(!m_Account.Login(tempName)) {
            correctInvalid();
            std::cin >> tempName;
        }

        readIn(tempName);
    }
    m_Choices = Choices(m_restVector);
    fillCuisineVector();
    // THIS IS FOR TESTING IF THE CUISINE VECTOR IS FILLED
    /*
    for (int i = 0; i < m_cuisineVector.size(); i++)
    {
        std::cout << m_cuisineVector.at(i) << "\n";
    }
    */


    while(m_menuChoice != EXIT_CODE)
    {
        m_menuChoice = m_Choices.printMenu();

        if(m_menuChoice == SHOW_ALL_CODE)
        {
            m_Choices.printAll();
        }
        else if(m_menuChoice == SEARCH_PRICE_CODE)
        {
            int lower, higher;
            std::cout << "1. $, 2. $$, 3. $$$\n(use the number lable to select the price range)\n";

            std::cout << "Please give a lower price range: ";
            std::cin >> lower;
            while(std::cin.fail() || lower < 1 || lower > 3) // lower has to be in and within range.
            {
                correctInvalid();
                std::cin >> lower;
            }

            std::cout << "Please give a higher price range: ";
            std::cin >> higher;
            while(std::cin.fail() || higher < lower || higher > 3) // higher has to be an int, has to be greater than or equal to lower, has to be with in highest range.
            {
                correctInvalid();
                std::cin >> higher;
            }

            m_Choices.printByPrice(lower, higher);


        }
        else if(m_menuChoice == SEARCH_TYPE_CODE)
        {
            int choice;
            for(int i=0; i < (int)m_cuisineVector.size(); i++)
            {
                std::cout << i+1 << ". " << m_cuisineVector.at(i) << "\n";
            }
            std::cout << "Please Select a cuisine: ";
            std::cin >> choice;
            while(std::cin.fail() || choice < 1 || choice > 24)
            {
                correctInvalid();
                std::cin >> choice;
            }

            m_Choices.printByCuisine(m_cuisineVector.at(choice-1));


        }
        else if(m_menuChoice == SEARCH_RATING_CODE) // Search By Ratings.
        {
            int typeChoice;
            double lowR, highR;
            std::cout << "Would you like to search by\n1. Personal Ratings\n2. Public Ratings\n";
            std::cin >> typeChoice;

            if(m_isReturning)
            {
                while(std::cin.fail() || typeChoice < 1 || typeChoice > 2)
                {
                    correctInvalid();
                    std::cin >> typeChoice;
                }
            }
            else
            {
                if(typeChoice == 1)
                {
                    std::cout << "You are not logged in. Please restart and login to use this feature.\n";
                }
                while(std::cin.fail() || typeChoice !=2)
                {
                    correctInvalid();
                    std::cin >> typeChoice;
                }
            }


            std::cout << "Please give a lower rating range(1.0-5.0): ";
            std::cin >> lowR;
            while(std::cin.fail() || lowR < 1 || lowR > 5) // lower has to be in and within range.
            {
                correctInvalid();
                std::cin >> lowR;
            }

            std::cout << "Please give a higher rating range(1.0-5.0): ";
            std::cin >> highR;
            while(std::cin.fail() || highR < lowR || highR > 5) // higher has to be an int, has to be greater than or equal to lower, has to be with in highest range.
            {
                correctInvalid();
                std::cin >> highR;
            }
            m_Choices.printByRating(typeChoice, lowR, highR);


        }
        else if(m_menuChoice == GIVE_RATING_CODE) // Give a rating.
        {
            if(m_isReturning)
            {
                std::string restChoice;
                std::unordered_set <std::string> checkerSet;
                double aRatingToAdd;

                std::cout << "Select a restaurant from the list below to add a rating to: \n";
                for(int i = 0; i < (int)m_restVector->size(); i++) {
                    std::cout << m_restVector->at(i).getName() << ", ";
                    checkerSet.insert(m_restVector->at(i).getName());
                    if(i != 0 && i % 4 == 0) {
                        std::cout << "\n";
                    }
                }
                std::cout << "Entry: ";
                std::cin >> restChoice;

                while(std::cin.fail() || (checkerSet.find(restChoice) == checkerSet.end())) {
                    correctInvalid();
                    std::cin >> restChoice;
                }

                std::cout << "Enter the rating that you would like to add: ";
                std::cin >> aRatingToAdd;

                while(std::cin.fail() || aRatingToAdd < 1 || aRatingToAdd > 5) {
                    correctInvalid();
                    std::cin >> aRatingToAdd;
                }

                m_Choices.giveRating(restChoice, aRatingToAdd);

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
                    correctInvalid();
                    std::cin >> restChoice;
                }

                m_Choices.removeRestaurant(restChoice);

            }
            else
            {
                std::cout << "You are not logged in. Please restart and login to use this feature.\n";
            }
        }
        else if(m_menuChoice == RANDOM_CODE) // Random.
        {
            m_Choices.printRandom();
        }
    }

    if(m_isReturning) {
        writeOut(tempName);
        std::cout << "Data saved!\n";
    }

    std::cout << "\nGoodbye!\n";
}

///function called when run method needs to read in from a file
/** If the user is a guest or new user, this is a standard file, otherwise it is under their username.*/
///@param fileToParse, the string that names the file to be read in
bool Executive::readIn(QString fileToParse)
{
    QFile m_file(fileToParse + ".txt");
    if(m_file.open(QIODevice::ReadOnly))
    {
        while(!m_file.atEnd())
        {
            //m_file >> m_tempRestName >> m_tempRestType >> m_tempPricing >> m_tempRating >> m_tempUserRating
            QString line = m_file.readLine();
            int pos = line.indexOf(" ");
            m_tempRestName = line.left(pos-1);
            line = line.right(line.size() - pos+1);
            pos = line.indexOf(" ");
            m_tempRestType = line.left(pos-1);
            line = line.right(line.size() - pos+1);
            pos = line.indexOf(" ");
            m_tempPricing = line.left(pos-1).toInt();
            line = line.right(line.size() - pos+1);
            pos = line.indexOf(" ");
            m_tempRating = line.left(pos-1).toDouble();
            line = line.right(line.size() - pos+1);
            pos = line.indexOf(" ");
            m_tempUserRating = line.left(pos-1).toDouble();
            line = line.right(line.size() - pos+1);

            Restaurant temp = Restaurant(m_tempRestName);
            temp.setCuisine(m_tempRestType);
            temp.setPrice(m_tempPricing);
            temp.setRating(m_tempRating);
            temp.setPRating(m_tempUserRating);
            m_restVector->push_back(temp);
        }
        // for (int i =0; i < int(m_restVector->size()); i++){ //just checking to make sure it reads it all
        //     std::cout << m_restVector->at(i).getName() << std::endl;
        // }
        m_file.close();
        return true;
    }
    else
    {
        //std::cout << "Couldn't open read " << fileToParse << " file!\n";
        return false;
    }
}

///function called when run methods needs to write to a file
/**If the user is a guest no write will happen, if they are a new user the file will be created, returning users overwrite old file.*/
///@param fileToWrite, the string that names the file to written to
void Executive::writeOut(QString fileToWrite)
{
    QFile m_file (fileToWrite + "txt");
    //m_file.open(QIODevice::WriteOnly | QIODevice::Text); // I believe the second arg will clear the file
    if(m_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out (&m_file);
        for(int i = 0; i< (int)m_restVector->size(); i++) {
            out << m_restVector->at(i).getName() << " " << m_restVector->at(i).getCusine()
            << " " << m_restVector->at(i).getPrice() << " " << m_restVector->at(i).getRating() << " " << m_restVector->at(i).getPRating() << std::endl;
        }
    }
    else
    {
        //std::cout << "Couldn't open write " << fileToWrite << " file!\n";
    }
}

///function called when run has the restaurant vector and needs to fill out cuisine vector
/**This vector is filled to use for printing all of the cuisine types that the user can search by*/
void Executive::fillCuisineVector()
{
    bool repeat = false;
    for(int i=0; i < (int)m_restVector->size(); i++) // fills in the cuisine vector, checks to make sure doesn't repeat a cuisine.
    {
        for(int j=0;  j < (int)m_cuisineVector.size(); j++) //probably rewrite this later to use a hash-table so we don't need nested for loops
        {
            try
            {
                if(m_restVector->at(i).getCusine() == m_cuisineVector.at(j))
                {
                    repeat = true;
                    break;
                }
                else
                {
                    repeat = false;
                }
            }
            catch (const std::out_of_range& oor)
            {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
        }
        if(!repeat)
        {
            m_cuisineVector.push_back(m_restVector->at(i).getCusine());
        }
    }
}

///Helper function to reduce code repition in input checks
void Executive::correctInvalid()
{
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
}
