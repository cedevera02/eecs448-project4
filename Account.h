#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <fstream>

class Account
{
    private:
        std::string m_accName;
       

    public:
        Account();
		bool Login(std::string name);
        void setName(std::string name);
        std::string getName();
        
        
};
#endif