#include "Executive.h"
#include <iostream>
#include <stdio.h>



Executive::Executive()
{
    m_restVector = new std::vector<Restaurant>;
    //I assume we'll want to create a UI object to be used here
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
            << " " << m_restVector->at(i).getPrice() << " " << m_restVector->at(i).getRating() << std::endl;
        }
    }
    else
    {
        std::cout << "Couldn't open write " << fileToWrite << " file!\n";
    }
}