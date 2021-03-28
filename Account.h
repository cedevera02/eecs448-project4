#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <fstream>

class Account
{
    private:
        std::string m_accName;
       

    public:
        Account(std::string fileName);
		bool Login();
        
        
};
#endif