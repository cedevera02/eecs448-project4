#include "Account.h"
#include <string>
#include <fstream>
#include <iostream>



Account::Account(std::string fileName)
{
    m_accName = fileName;

}



//login checks to see if name of account is valid. If not, login fails.
bool Account::Login()
{ 
    std::ofstream file;
    file.open(m_accName.c_str());//to allow for using variable name
    if (file.is_open())
    {
        std::cout<<"Welcome"<<m_accName<<"back\n";
        file.close();
        return(true);
    }
    else
    {   
        return(false);
      
    }
}

