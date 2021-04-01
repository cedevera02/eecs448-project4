#include "Account.h"
#include <string>
#include <fstream>
#include <iostream>



Account::Account()
{
    m_accName = '\0';
}



//login checks to see if name of account is valid. If not, login fails.
bool Account::Login(std::string name)
{ 
    std::ofstream file;
    file.open(name + ".txt");//to allow for using variable name
    if (file.is_open())
    {
        std::cout<<"Welcome "<<m_accName<<" back\n";
        file.close();
        return(true);
    }
    else
    {   
        return(false);
      
    }
}

void Account::setName(std::string name)
{
    m_accName = name;
}

std::string Account::getName()
{
    return m_accName;
}

