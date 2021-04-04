#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <fstream>

///This is a small class that handles the user login and their name

class Account
{
    private:
        std::string m_accName;///< String variable to hold the account name
       

    public:
        Account();/// Simple constructor to inizalize account name
		bool Login(std::string name);/// Method to have a user login, handles failed user names. Returns true if sucessful login
        void setName(std::string name);/// Helper function to set the account name
        std::string getName();/// Helper function to get the account name
        
        
};
#endif