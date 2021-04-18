#include "Account.h"
#include <string>
#include <fstream>
#include <iostream>


///ACCOUNT CONSTRUCTOR
///
///This will initialize the account name to null char
Account::Account()
{
    m_accName = '\0';
}



///METHODS
///
///This attempts a user account login
///@param name, String that is the accoutn name that user enters
///@return Returns true if can login (open the file) using the given name, false otherwise
bool Account::Login(std::string name)
{
    std::ifstream file;
    file.open(name + ".txt");//to allow for using variable name
    if (file.is_open())
    {
        std::cout<<"Welcome back" << m_accName << "\n";
        file.close();
        return(true);
    }
    else
    {
        return(false);

    }
}

///Helper function to set the local user name variable
void Account::setName(std::string name)
{
    m_accName = name;
}

///Helper function to get the local user name varialbe
///
///@return Returns the user name string
std::string Account::getName()
{
    return m_accName;
}

